
 
#***********************************************************************##Aim : To monitor traffic for Bus topology using NS2#***********************************************************************##Create a simulator objectset ns [new Simulator]#Open the nam trace fileset nf [open out.nam w]$ns namtrace-all $nf#Define a 'finish' procedureproc finish {} {global ns nf$ns flush-trace#Close the trace fileclose $nf#Executenam on the trace fileexec nam out.nam &exit 0}#Create four nodesset n0 [$ns node]set n1 [$ns node]set n2 [$ns node]set n3 [$ns node]set n4 [$ns node]#CreateLanbetween the nodesset lan0 [$ns newLan "$n0 $n1 $n2 $n3 $n4" 0.5Mb 40ms LL Queue/DropTail MAC/Csma/CdChannel]#Create a TCP agent and attach it to node n0set tcp0 [new Agent/TCP]$tcp0 set class_ 1$ns attach-agent $n1 $tcp0#Create a TCP Sink agent (a traffic sink) for TCP and attach it to node n3set sink0 [new Agent/TCPSink]$ns attach-agent $n3 $sink0#Connect the traffic sources with the traffic sink$ns connect $tcp0 $sink0# Create a CBR traffic source and attach it to tcp0set cbr0 [new Application/Traffic/CBR]$cbr0 set packetSize_ 500$cbr0 set interval_ 0.01$cbr0 attach-agent $tcp0#Schedule events for the CBR agents$ns at 0.5 "$cbr0 start"$ns at 4.5 "$cbr0 stop"#Call the finish procedure after 5 seconds of simulation time$ns at 5.0 "finish"#Run the simulation$ns run
#Create a Simulator Object
set ns [new Simulator]

#Open the nam trace file
set nf [open out.nam w]
$ns namtrace-all $nf


#Define a 'finish' procedure
proc finish {} {
    global ns nf
    $ns flush-trace
    #Close the trace file
    close $nf
    #Executenam on the trace file
    exec nam out.nam &
    exit 0
}

#Create four nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

#Create LAN between the nodes
set lan0 [$ns newLan "$n0 $n1 $n2 $n3 $n4" 0.5Mb 40ms LL Queue/DropTail MAC/Csma/Cd MAC/Csma/CdChannel]

#Create a TCP agent and attach it to node 0
set tcp0 [new Agent/TCP]
$ns attach-agent $n1 $tcp0

#Create a TCP Sink agent for TCP and attach it to node n3
set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0

#connect the traffic sources with the traffic sink
$ns connect $tcp0 $sink0

#Create a CBR Traffic source and attach it to the tcp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.01
$cbr0 attach-agent $tcp0

#Schedule events for the cbr AGENTS
$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"

#Call the finish procedure after 5 seconds of simulation time
$ns at 5.0 "finish"

#Run the simulation
$ns run