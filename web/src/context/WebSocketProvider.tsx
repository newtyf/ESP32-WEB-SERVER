import { ReactNode, useEffect } from "react";
import { WebSocketContext } from "./WebSocketContext";
import { websocketService } from "@/services/websocketService";

interface WebSocketProviderProps {
  children: ReactNode;
}

export const WebSocketProvider: React.FC<WebSocketProviderProps> = ({ children }) => {
  useEffect(() => {
      websocketService.connect();
  }, []);

  return (
      <WebSocketContext.Provider value={{ websocketService }}>
          {children}
      </WebSocketContext.Provider>
  );
};