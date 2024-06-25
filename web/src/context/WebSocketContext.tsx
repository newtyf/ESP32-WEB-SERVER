import { createContext } from "react";
import { WebSocketService } from "../services/websocketService";

interface WebSocketContextType {
  websocketService: WebSocketService;
}

export const WebSocketContext = createContext<WebSocketContextType | undefined>(
  undefined
);
