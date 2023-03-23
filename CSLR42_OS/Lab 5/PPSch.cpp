//Preemptive Priority Scheduling

/*   
Process    Arrival   Priority    Burst
  P0         0          1          3
  P1         1          2          4
  P2         2          3          6
  P3         3          4          4
  P4         4          5          2

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Process {
	int arrival, burst, priority, exec;
	bool arrived, dead;
} p[5];

int n = 5;

int main() {
	//Setting processes
	p[0].arrival = 0, p[0].burst = 3, p[0].priority = 3, p[0].exec = 0, p[0].arrived = false, p[0].dead = false;
	p[1].arrival = 1, p[1].burst = 4, p[1].priority = 2, p[1].exec = 0, p[1].arrived = false, p[1].dead = false;
	p[2].arrival = 3, p[2].burst = 6, p[2].priority = 4, p[2].exec = 0, p[2].arrived = false, p[2].dead = false;
	p[3].arrival = 3, p[3].burst = 5, p[3].priority = 1, p[3].exec = 0, p[3].arrived = false, p[3].dead = false;
	p[4].arrival = 6, p[4].burst = 2, p[4].priority = 10, p[4].exec = 0, p[4].arrived = false, p[4].dead = false;
	
	//Sorting based on arrival time
	//for(int i = 0; i < 5; i++) {
	//	for(int j = 0; j < 5-i-1; j++) {
	//		if(p[i].arrival > p[i+1].arrival) {
	//			int temp = p[i].arrival;
	//			p[i].arrival = p[i+1].arrival;
	//			p[i+1].arrival = temp;
	//		}
	//	}
	//}	
	
	int time = 0, curr, max = 0, maxInd = 0;
	int total_time=0, i;
    for(i=0; i<5; i++)
    {
        total_time+=p[i].burst;
    }
	//Increases time for process with max priority
	while(time < total_time) {
		//Checks if a process has arrived or not
		for(int i = 0; i < n; i++) {
			if(p[i].arrival <= time && !p[i].dead) {
				p[i].arrived = true;
			}
		}
		//Finds process with max priority
		for(int i = 0; i < n; i++) {
			if(p[i].arrived && p[i].priority > max && !p[i].dead) {
				max = p[i].priority;
				maxInd = i;
			}
		}
		p[maxInd].exec++;
		time++;
		if(p[maxInd].exec == p[maxInd].burst) {
			p[maxInd].dead = true;
			p[maxInd].arrived = false;
			max = 0;
		}
		cout << "Current Process: "<< maxInd;
        cout<< "    Executed for: "<< p[maxInd].exec;
		cout << "    Time = " << time << endl;
	}	
	return 0;
}
