import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import {
  Tooltip,
  TooltipContent,
  TooltipProvider,
  TooltipTrigger,
} from "@radix-ui/react-tooltip";
import { BadgeCheck, TriangleAlert } from "lucide-react";

interface Props {
  waterTankLevel: number;
}

export const WaterTankLevel = ({ waterTankLevel }: Props) => {
  return (
    <Card className='min-h-96 h-full flex flex-col'>
      <CardHeader className='px-3 py-2'>
        <CardTitle className='scroll-m-20 text-base font-extrabold tracking-tight flex justify-between items-center'>
          Nivel de agua del tanque
          {waterTankLevel <= 25 && (
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
          {25 < waterTankLevel && waterTankLevel <= 100 && (
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
          Cantidad de Agua Actual:
          <span className='font-bold'>{waterTankLevel}%</span>
        </h4>
        <div className='border border-t-0 border-dashed border-gray-500 flex-1 relative mt-8 rounded-lg'>
          <div
            className={`absolute bottom-0 bg-sky-400 w-full rounded-lg`}
            style={{
              height: (waterTankLevel > 100 ? 100 : waterTankLevel) + "%",
            }}
          >
            {
              waterTankLevel > 10 && <div className="hero_area">
              <svg className="waves -bottom-6" xmlns="http://www.w3.org/2000/svg" xmlnsXlink="http://www.w3.org/1999/xlink" viewBox="0 24 150 28" preserveAspectRatio="none" shape-rendering="auto">
                <defs>
                  <path id="gentle-wave" d="M-160 44c30 0 58-18 88-18s 58 18 88 18 58-18 88-18 58 18 88 18 v44h-352z" />
                </defs>
                <g className="parallax">
                  <use xlinkHref="#gentle-wave" x="48" y="0" fill="rgba(56,189,248,0.7" />
                  <use xlinkHref="#gentle-wave" x="48" y="3" fill="rgba(56,189,248,0.5)" />
                  <use xlinkHref="#gentle-wave" x="48" y="5" fill="rgba(56,189,248,0.3)" />
                  <use xlinkHref="#gentle-wave" x="48" y="7" fill="rgba(56,189,248)" />
                </g>
              </svg>
            </div>
            }
          </div>

          <div className='absolute w-full h-full'>
            <div
              className='absolute border-b border-dashed border-gray-500 w-full text-right'
              style={{ bottom: "0%" }}
            >
              <span className='pr-2'>0%</span>
            </div>
            <div
              className='absolute border-b border-dashed border-gray-500 w-full text-right'
              style={{ bottom: "25%" }}
            >
              <span className='pr-2'>25%</span>
            </div>
            <div
              className='absolute border-b border-dashed border-gray-500 w-full text-right'
              style={{ bottom: "50%" }}
            >
              <span className='pr-2'>50%</span>
            </div>
            <div
              className='absolute border-b border-dashed border-gray-500 w-full text-right'
              style={{ bottom: "75%" }}
            >
              <span className='pr-2'>75%</span>
            </div>
            <div
              className='absolute border-b border-dashed border-gray-500 w-full text-right'
              style={{ bottom: "100%" }}
            >
              <span className='pr-2'>100%</span>
            </div>
          </div>
        </div>
      </CardContent>
    </Card>
  );
};
