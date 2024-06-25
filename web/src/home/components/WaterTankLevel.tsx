import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import {
  Tooltip,
  TooltipContent,
  TooltipProvider,
  TooltipTrigger,
} from "@radix-ui/react-tooltip";
import { BadgeCheck, TriangleAlert } from "lucide-react";

interface Props {
  waterTankLevel: number
}

export const WaterTankLevel = ({waterTankLevel}: Props) => {
  return (
    <Card className='min-h-96 h-full flex flex-col'>
      <CardHeader className='px-3 py-2'>
        <CardTitle className='scroll-m-20 text-base font-extrabold tracking-tight flex justify-between items-center'>
          Nivel de agua del tanque
          {waterTankLevel <= 500 && (
            <TooltipProvider>
              <Tooltip>
                <TooltipTrigger>
                  <TriangleAlert className='text-red-500' />
                </TooltipTrigger>
                <TooltipContent className='bg-neutral-800 rounded-lg mb-2 p-2'>
                  <p className='text-sm '>El nivel del agua es muy baja 😱</p>
                </TooltipContent>
              </Tooltip>
            </TooltipProvider>
          )}
          {500 < waterTankLevel && waterTankLevel < 1000 && (
            <TooltipProvider>
              <Tooltip>
                <TooltipTrigger>
                  <BadgeCheck className='text-green-500' />
                </TooltipTrigger>
                <TooltipContent className='bg-neutral-800 rounded-lg mb-2 p-2'>
                  <p className='text-sm '>El nivel del agua esta preciso 😎</p>
                </TooltipContent>
              </Tooltip>
            </TooltipProvider>
          )}
        </CardTitle>
      </CardHeader>
      <CardContent className='px-3 py-2 flex-1 flex flex-col'>
        <h4 className='scroll-m-20 text-sm tracking-tight'>
          Cantidad de Agua Actual:{" "}
          <span className='font-bold'>{waterTankLevel}ml</span>
        </h4>
        <div className='border border-t-0 border-dashed border-gray-500 flex-1  relative mt-8 rounded-lg'>
          <div
            className={`absolute bottom-0 bg-sky-400 w-full rounded-lg`}
            style={{ height: waterTankLevel / 20 + "%" }}
          ></div>
          <div className='absolute w-full h-full'>
            <div
              className='absolute border-b border-dashed border-gray-500 w-full text-right'
              style={{ bottom: "0%" }}
            >
              <span className='pr-2'>0 ml</span>
            </div>
            <div
              className='absolute border-b border-dashed border-gray-500 w-full text-right'
              style={{ bottom: "25%" }}
            >
              <span className='pr-2'>500 ml</span>
            </div>
            <div
              className='absolute border-b border-dashed border-gray-500 w-full text-right'
              style={{ bottom: "50%" }}
            >
              <span className='pr-2'>1000 ml</span>
            </div>
            <div
              className='absolute border-b border-dashed border-gray-500 w-full text-right'
              style={{ bottom: "75%" }}
            >
              <span className='pr-2'>1500 ml</span>
            </div>
            <div
              className='absolute border-b border-dashed border-gray-500 w-full text-right'
              style={{ bottom: "100%" }}
            >
              <span className='pr-2'>2000 ml</span>
            </div>
          </div>
        </div>
      </CardContent>
    </Card>
  );
};
