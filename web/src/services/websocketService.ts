/* eslint-disable @typescript-eslint/no-explicit-any */
interface Listener {
  [event: string]: Array<(payload: any) => void>;
}

export class WebSocketService {
  private url: string;
  private socket: WebSocket | null = null;
  private listeners: Listener = {};

  constructor(url: string) {
    this.url = url;
  }

  connect() {
    if (!this.socket || this.socket.readyState === WebSocket.CLOSED) {
      this.socket = new WebSocket(this.url);

      this.socket.onopen = () => {
        console.log("Conectado al servidor WebSocket");
      };

      this.socket.onmessage = (event: MessageEvent) => {
        const data = JSON.parse(event.data);
        if (this.listeners[data.event]) {
          this.listeners[data.event].forEach((callback) =>
            callback(data.payload)
          );
        }
      };

      this.socket.onclose = () => {
        console.log("Desconectado del servidor WebSocket");
      };

      this.socket.onerror = (error: Event) => {
        console.error("Error en la conexión WebSocket", error);
      };

    }
  }

  emit(event: string, payload: any) {
    if (this.socket) {
      this.socket.send(JSON.stringify({ event, payload }));
    }
  }

  on(event: string, callback: (payload: any) => void) {
    if (!this.listeners[event]) {
      this.listeners[event] = [];
    }
    this.listeners[event].push(callback);
  }

  off(event: string, callback: (payload: any) => void) {
    if (!this.listeners[event]) return;
    this.listeners[event] = this.listeners[event].filter(
      (cb) => cb !== callback
    );
  }
}

export const websocketService = new WebSocketService(
  "ws://socket-rps.apps.newtyf.com/gamehub"
);
