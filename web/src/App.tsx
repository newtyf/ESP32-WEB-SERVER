import { ThemeProvider } from "./components/theme-provider";
import { WebSocketProvider } from "@/context/WebSocketProvider";
import { Dashboard } from "./home/views/Dashboard";

function App() {
  return (
    <ThemeProvider defaultTheme='dark' storageKey='vite-ui-theme'>
      <WebSocketProvider>
        <Dashboard />
      </WebSocketProvider>
    </ThemeProvider>
  );
}

export default App;
