[Transient Analysis]
{
   Npanes: 2
   {
      traces: 3 {524290,0,"V(vin)"} {589830,0,"V(voutput)"} {524291,0,"V(Vin,Voutput)"}
      X: ('m',1,0,0.0001,0.001)
      Y[0]: (' ',0,0,1,12)
      Y[1]: ('_',0,1e+308,0,-1e+308)
      Volts: (' ',0,0,1,0,0.6,12)
      Log: 0 0 0
      GridStyle: 1
   },
   {
      traces: 3 {34603013,0,"I(R2)"} {34668548,0,"I(V1)"} {589832,1,"V(Vin,Voutput)*I(R2)"}
      X: ('m',1,0,0.0001,0.001)
      Y[0]: ('m',1,-0.0014,0.0002,0.0014)
      Y[1]: ('m',3,0.003994,1e-06,0.004008)
      Amps: ('m',0,0,3,-0.0012,0.0002,0.0012)
      Units: "W" ('m',0,0,2,0.003996,8e-07,0.0040056)
      Log: 0 0 0
      GridStyle: 1
   }
}

