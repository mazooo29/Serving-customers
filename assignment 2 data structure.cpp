#include<iostream>
#include<stack>
using namespace std;
const int maxsize = 500;
template <class T>
class queue
{
	int front,count,rear; 
	T entry[maxsize];
	public:
	queue(){front=0;rear=maxsize-1;count=0;}
	bool empty(){return (count==0);}
	bool append(T item){if(count==maxsize)return 0;rear=(rear+1)%maxsize;entry[rear]=item;count++;return 1;}
	bool serve(){if(empty())return 0;front=(front+1)%maxsize;count--;return 1;}
	bool retrieve(T &item){if(empty())return 0;item=entry[front];return 1;}
};
main()
{
	queue <string>q;
	int CpeopleServed=0,Cwaiting=0,n,k,total,cwt=0;
	double avgwait;
	string s1,s2;
    cout<<" enter the number of reception times : ";
    cin>>n;
    cout<<endl;
    cout<<"first time is 1 after it is rondom between 0-2 passengrs!!"<<endl;
    CpeopleServed++;cwt++;
    for(int i=1;i<n;i++)
    {
		 
		k=rand()%3;
   	 cout<<"["<<k<<"] passengers came this time"<<endl;

	    if(k==0){
		cout<<" no-one"<<endl;
		if(CpeopleServed>1)
		cwt+=-1;
        continue;
		}
    	else if(k==1){
   		cout<<" please enter id of passenger ticket : ";
        cin>>s1;
        q.append(s1);
        CpeopleServed++;
        cwt+=CpeopleServed;

      
             }
        else if(k==2){
     	cout<<" please enter id of passenger ticket : ";
        cin>>s1;
		cout<<endl;
		cout<<" please enter id of passenger ticket : ";
		cin>>s2;
		cout<<endl; 
        q.append(s1);
		q.append(s2);
		CpeopleServed++;	
        Cwaiting++;
        cwt+=Cwaiting;
             }
    }
  		 total=CpeopleServed+Cwaiting;
  		 avgwait = (cwt*1.0)/total;
  		 string item,PWMPOT;
  		
	     cout<<"__________________________________________________________\n";
	     cout<<"\n passengers served ===> "<<CpeopleServed<<endl;// *
         cout<<"---------------------------------------------\n";
         cout<<" passengers that wait Maximum on the line ===> "<<Cwaiting<<endl;
         cout<<"---------------------------------------------\n";
         cout<<" all waiting time for all passengers ===> "<<cwt<<endl;
         cout<<"---------------------------------------------\n";
         cout<<" time total for serving all passengers (minutes) ===> "<<total<<endl;//*
         cout<<"---------------------------------------------\n";
         stack <string>s;
         while(!q.empty())
         {
         	q.retrieve(item);
        	 s.push(item);
        	 q.serve();
         }
         PWMPOT = s.top();//passenger waiting max period of time(PWMROT)
         cout<<" passenger that wait the max period of time ===> ("<<PWMPOT<<") and he waits ("<<Cwaiting<<") minutes "<<endl;//*
         cout<<"---------------------------------------------\n";
         cout<<"  average wait ===> "<<avgwait<<endl;
         cout<<"___________________________________________________________\n";
         
         
 			
	}
