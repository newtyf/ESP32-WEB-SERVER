import {
  Table,
  TableBody,
  TableCaption,
  TableCell,
  TableHead,
  TableHeader,
  TableRow,
} from "@/components/ui/table";

import { WebSocketContext } from "@/context/WebSocketContext";
import { useContext, useEffect, useState } from "react";

interface Event {
  date: string;
  event: string;
}

const now = (
  new Date().getDate() +
  "/" +
  new Date().getMonth() +
  "/" +
  new Date().getFullYear()
).toString();

export const ListRecentActivities = () => {
  const { websocketService } = useContext(WebSocketContext)!;
  const [events, setEvents] = useState<Event[]>([
    {
      date: now,
      event: "Se encendió el led lorem adwdawd wd awd awd wa wa",
    },
    {
      date: now,
      event: "Se encendió el led lorem adwdawd wd awd awd wa wa",
    },
    {
      date: now,
      event: "Se encendió el led lorem adwdawd wd awd awd wa wa",
    },
    {
      date: now,
      event: "Se encendió el led lorem adwdawd wd awd awd wa wa",
    },
    {
      date: now,
      event: "Se encendió el led lorem adwdawd wd awd awd wa wa",
    },
    {
      date: now,
      event: "Se encendió el led lorem adwdawd wd awd awd wa wa",
    },
  ]);

  useEffect(() => {
    const handleEvents = (payload: string) => {
      setEvents(events.concat(JSON.parse(payload)));
    };

    websocketService.on("events", handleEvents);

    return () => {
      websocketService.off("events", handleEvents);
    };
  }, [events, websocketService]);

  return (
    <Table>
      <TableCaption>Lista de eventos ocurridos en el sistema</TableCaption>
      <TableHeader>
        <TableRow>
          <TableHead className='w-[100px]'>Fecha</TableHead>
          <TableHead>Evento</TableHead>
        </TableRow>
      </TableHeader>
      <TableBody>
        {events.map(({ date, event }, index) => (
          <TableRow key={index}>
            <TableCell className='font-medium'>{date}</TableCell>
            <TableCell className='text-left'>{event}</TableCell>
          </TableRow>
        ))}
      </TableBody>
    </Table>
  );
};
