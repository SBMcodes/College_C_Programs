#include <stdlib.h>
#include<stdio.h>
#include<stdbool.h>

// ©SBM
// What is Job Sequencing Problem and How to solve it?
// In this problem we are given a set of jobs with their deadlines and their profit
// Now here deadline means we have to complete the job by that time
// For example if we are given three jobs j1,j2 and j3 where they have
// deadline as 1,2,2 and job j1 has profit 10 and j2 has profit 20 and j3 has profit 30
// We have to assume each job takes 1 unit of time (hour in this case)
// First we will sort the jobs in descending order accorading to their profit
// then we will assign slot to them accorading to their deadline
// After sorting --> j3( 30 | 2 ),j2( 20 | 2 ),j1( 10 | 1 )
// So here our 1st job accorading to profit is j3 and we have to complete it by 2nd hour
// so we will assign last available free slot (accorading to its deadline) to it i.e. 2nd slot
// next job j2 has deadline of 2nd hour but 2nd slot is already filled slot after that is first slot
// so we will assign first slot to it
// next job j3 has deadline by 1st hour but 1st slot is already filled so we can't assign any slot for this job
// and that's how we solved job sequencing with deadline problem









// Declaring Struct Job type here
typedef struct Job{
	char* id;
	int deadline;
	int profit;
}Job;



//List of all jobs
Job allJobs[] = {
{"first-job",1,10},
{"sec-job",2,20},
{"third-job",2,30},
{"fourth-job",1,50},
{"fifth-job",3,5},
};


// In this program we have assume total number of free slots available is the total number of jobs
// i.e. in this we have 5 free slots
const int totalJobs = sizeof(allJobs)/sizeof(allJobs[0]);
int* scheduledJobsIndex;












// Helper function to print array of job type
void printJobs(Job* jobs){
	int i;
	for(i=0;i<totalJobs;i++){
		printf("%s\n",jobs[i].id);
		
	}
}


// Helper function for qsort to help sort the jobs accorading to their profit
int compareJobs(const void* a,const void* b){
	Job* tempa = (Job*) a;
	Job* tempb = (Job*) b;
	return (tempb->profit - tempa->profit);
}


// Prints all scheduled jobs
void printScheduledJobs(){
	int i;
	for(i=0;i<totalJobs;i++){
		if(scheduledJobsIndex[i] != -1){
			printf("Slot %d: ",i+1);
			printf("%s ",allJobs[scheduledJobsIndex[i]].id);
			printf("\tProfit: %d\n",allJobs[scheduledJobsIndex[i]].profit);
		}
	}
}

void findJobScheduling(){
	
	//qsort helps us to sort an array accorading to result of a function we have provided
	//It takes four input arr*, arrLength, sizeofEachArrItem,functionToCompare
	//Here we are sorting the jobs accorading to their profit in descending order
	qsort(allJobs,totalJobs,sizeof(allJobs[0]),compareJobs);
	
	
	int i,j,minTime;
	
//	Looping through all the jobs which is already sorted accorading to profit in their descending order
	for(i=0;i<totalJobs;i++){
		
		// Finding minTime between totalJobs(last free slot) and deadline of current job
		minTime = (totalJobs<allJobs[i].deadline)?totalJobs:allJobs[i].deadline;
		
		
		for(j=minTime-1;j>=0;j--){
			if(scheduledJobsIndex[j]==-1){
				scheduledJobsIndex[j] = i;
				break;
			}
		}
	}	
}








int main(){
	
	scheduledJobsIndex = (int*)malloc(sizeof(int) * totalJobs);
	
	int i;
	for(i=0;i<totalJobs;i++){
		scheduledJobsIndex[i] = -1;
	}
	
	findJobScheduling();
	printScheduledJobs();
	
	return 0;
}
