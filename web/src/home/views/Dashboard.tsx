import { Droplets, Thermometer, Waves, Wind, Zap } from "lucide-react";
import { Switch } from "@/components/ui/switch";

import { ModeToggle } from "../../components/mode-toggle";
import { CardForMetrics } from "../components/CardForMetrics";
import { DashboardLayout } from "../layout/DashboardLayout";
import { ListRecentActivities } from "../components/ListRecentActivities";
import { WaterTankLevel } from "../components/WaterTankLevel";

import { useContext, useEffect, useState } from "react";
import { WebSocketContext } from "@/context/WebSocketContext";

export const Dashboard = () => {
  const [systemStatus, setSystemStatus] = useState<boolean>(false);
  const [groundHumidity, setGroundHumidity] = useState<string>();
  const [ambientTemperature, setAmbientTemperature] = useState<string>();
  const [ventiladorStatus, setVentiladorStatus] = useState<boolean>(false);
  const [pumpWaterStatus, setPumpWaterStatus] = useState<boolean>(false);
  const [focoStatus, setFocoStatus] = useState<boolean>(false);
  const [waterTankLevel, setWaterTankLevel] = useState<number>(100);

  const { websocketService } = useContext(WebSocketContext)!;

  useEffect(() => {
    websocketService.on("newHumidity", () => setGroundHumidity("22.00"));
    websocketService.on("newTemperature", () => setAmbientTemperature("18.00"));
    websocketService.on("systemStatus", () => setSystemStatus(true));
    websocketService.on("ventiladorStatus", () => setVentiladorStatus(true));
    websocketService.on("focoStatus", () => setFocoStatus(true));
    websocketService.on("pumpWaterStatus", () => setPumpWaterStatus(true));
    websocketService.on("waterTankLevel", () => setWaterTankLevel(1200));

    return () => {};
  }, [websocketService]);

  const onChangeVentilador = () => {
    //? so here we emit the event to change the status of ventilador
    setVentiladorStatus(!ventiladorStatus);
  };

  const onChangeFoco = () => {
    //? so here we emit the event to change the status of foco
    setFocoStatus(!focoStatus);
  };

  const onChangePumpWater = () => {
    //? so here we emit the event to change the status of foco
    setPumpWaterStatus(!pumpWaterStatus);
  };

  return (
    <DashboardLayout>
      <header className='flex justify-between border p-4'>
        <h1 className='scroll-m-20 text-3xl font-extrabold tracking-tight lg:text-4xl'>
          Sistema de Riego
        </h1>
        <div className='flex items-center'>
          <p className='mr-3'>
            Estado del sistema:
            <span
              className={
                "block lg:ml-1 lg:inline " +
                (systemStatus ? "text-green-400" : "text-red-500")
              }
            >
              {systemStatus ? "FUNCIONANDO" : "APAGADO"}
            </span>
          </p>
          <ModeToggle />
        </div>
      </header>
      <main className='border grid grid-cols-12 gap-4 p-4'>
        <section
          id='metrics'
          className='grid col-span-12 pb-2 gap-4 lg:grid-cols-4'
        >
          <CardForMetrics title='Humedad de la Tierra' Icon={Droplets}>
            <h3 className='scroll-m-20 text-xl font-extrabold tracking-tight'>
              {groundHumidity ? groundHumidity + "%" : "No se reciben datos"}
            </h3>
          </CardForMetrics>
          <CardForMetrics title='Temperatura Ambiental' Icon={Thermometer}>
            {ambientTemperature && (
              <div className='flex gap-2 items-center h-10'>
                <span>10°</span>
                <div className='relative h-3 w-full rounded-full overflow-hidden bg-gradient-to-r from-sky-400 to-orange-500 to-100%'>
                  <div
                    className='absolute top-0 bottom-0 w-1 ml-1 bg-black'
                    style={{ left: (parseInt(ambientTemperature) / 20) * 100 }}
                  ></div>
                </div>
                <span>30°</span>
              </div>
            )}
            <h3 className='scroll-m-20 text-xl font-extrabold tracking-tight'>
              {ambientTemperature
                ? ambientTemperature + "° Celsius"
                : "No se reciben datos"}
            </h3>
          </CardForMetrics>
          <CardForMetrics title='Estado del Ventilador' Icon={Wind}>
            <div className='flex'>
              <Switch
                checked={ventiladorStatus}
                onCheckedChange={onChangeVentilador}
              />
              <h3
                className={
                  "ml-2 scroll-m-20 text-sm font-extrabold tracking-tight " +
                  (ventiladorStatus ? "text-green-400" : "text-red-500")
                }
              >
                {ventiladorStatus ? "Encendido" : "Apagado"}
              </h3>
            </div>
          </CardForMetrics>
          <CardForMetrics title='Estado del Foco' Icon={Zap}>
            <div className='flex'>
              <Switch checked={focoStatus} onCheckedChange={onChangeFoco} />
              <h3
                className={
                  "ml-2 scroll-m-20 text-sm font-extrabold tracking-tight " +
                  (focoStatus ? "text-green-400" : "text-red-500")
                }
              >
                {focoStatus ? "Encendido" : "Apagado"}
              </h3>
            </div>
          </CardForMetrics>
          <CardForMetrics title='Estado de la Bomba' Icon={Waves}>
            <div className='flex'>
              <Switch checked={pumpWaterStatus} onCheckedChange={onChangePumpWater} />
              <h3
                className={
                  "ml-2 scroll-m-20 text-sm font-extrabold tracking-tight " +
                  (pumpWaterStatus ? "text-green-400" : "text-red-500")
                }
              >
                {pumpWaterStatus ? "Encendido" : "Apagado"}
              </h3>
            </div>
          </CardForMetrics>
        </section>
        <section id='water-level' className='col-span-12 lg:col-span-7'>
          <WaterTankLevel waterTankLevel={waterTankLevel} />
        </section>
        <section id='events' className='col-span-12 lg:col-span-5'>
          <ListRecentActivities />
        </section>
      </main>
    </DashboardLayout>
  );
};
