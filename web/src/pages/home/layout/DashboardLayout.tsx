import { PropsWithChildren } from "react";

export const DashboardLayout = ({ children }: PropsWithChildren) => {
  return <div className="max-w-screen-xl mx-auto p-4">{children}</div>;
};
