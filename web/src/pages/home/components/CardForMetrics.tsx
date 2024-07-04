import { LucideProps } from "lucide-react";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { ForwardRefExoticComponent, PropsWithChildren } from "react";

interface Props {
  title: string;
  color?: string;
  Icon: ForwardRefExoticComponent<
    Omit<LucideProps, "ref"> & React.RefAttributes<SVGSVGElement>
  >;
}

export function CardForMetrics({
  title,
  Icon,
  color = "#22b357",
  children,
}: PropsWithChildren<Props>) {
  return (
    <Card className='flex flex-col min-w-56'>
      <CardHeader className='px-3 py-2 flex-1'>
        <CardTitle className='scroll-m-20 text-base font-light tracking-tight flex justify-between items-center'>
          {title} <Icon color={color} size={20} />
        </CardTitle>
      </CardHeader>
      <CardContent className='px-3 py-2'>{children}</CardContent>
    </Card>
  );
}
