#include <bits/stdc++.h>
using namespace std;



int Num = 1;
double R_resolution = 0.01;
double Rth = 5.0;
double dis = 0xfff;
double N_strong = -999; 
double N_weak = -20; 
double ground_undulation = 0.1;
double elevation_Boundary = 5;


double Function_V_value(double z1, double z2, double dis)
{
	if(abs(z1-z2) <= ground_undulation)
	{
		if (dis <= 1) return N_strong;
		else if (dis <= 2) return N_weak;
	}
	else if(abs(z1-z2) >= elevation_Boundary) return 0;
	return abs(z1 - z2);
}


double DistanceFunction(double &dis)
{
	return 1.0/(double)((int)(dis / R_resolution));
}


typedef struct PointCloudStruct
{
	double x;
	double y;
	double z;
//	int r;
//	int g;
//	int b;
//	int intensity; 
	double value;
} PointCloudStruct;

PointCloudStruct PointCloudData[40000000];


double distance(double x1, double y1, double x2, double y2)
{
	double temp = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return temp;
}



int main()
{
	freopen("C:\\ALS.txt","r",stdin); //type your own path here to read the pointcloud data.
cout<<"loading" <<endl;

//while(cin>>PointCloudData[Num].x>>PointCloudData[Num].y>>PointCloudData[Num].z>>PointCloudData[Num].intensity)
while(cin>>PointCloudData[Num].x>>PointCloudData[Num].y>>PointCloudData[Num].z)//depend on your input pointcloud data information.
{
	PointCloudData[Num].value = 0;
	Num++;
}
Num--;

cout<<"loading completed!"<<endl;
cout<<"running"<<endl;

int PointCloudNum = Num;

for(int i = 1; i<= PointCloudNum; i++)
{
	for(int k = 1 ; k <= PointCloudNum; k++)
	{
		dis = distance(PointCloudData[i].x,PointCloudData[i].y,PointCloudData[k].x,PointCloudData[k].y);
		if((k == i) || (dis >= Rth)) continue;
		else PointCloudData[i].value += (DistanceFunction(dis) * Function_V_value(PointCloudData[i].z , PointCloudData[k].z , dis));
	}
	
	//Test that the program is running properly 
	if(i == 100) cout<<"100"<<endl; 
	
	if(i == int(PointCloudNum* 0.1)) cout<<"10%"<<endl; 
	if(i == int(PointCloudNum* 0.2)) cout<<"20%"<<endl; 
	if(i == int(PointCloudNum* 0.3)) cout<<"30%"<<endl; 
	if(i == int(PointCloudNum* 0.4)) cout<<"40%"<<endl; 
	if(i == int(PointCloudNum* 0.5)) cout<<"50%"<<endl; 
	if(i == int(PointCloudNum* 0.6)) cout<<"60%"<<endl; 
	if(i == int(PointCloudNum* 0.7)) cout<<"70%"<<endl; 
	if(i == int(PointCloudNum* 0.8)) cout<<"80%"<<endl; 
	if(i == int(PointCloudNum* 0.9)) cout<<"90%"<<endl; 
	if(i == int(PointCloudNum* 1.0)) cout<<"100%"<<endl; 
}

cout<<"writing"<<endl;  

freopen("F:\\output.txt","w",stdout);//type your own path here to write the pointcloud data.

for(int i = 1; i<= PointCloudNum; i++)
{
	if(PointCloudData[i].value >= 0)
	{
		//printf("%lf  %lf  %lf  %d",PointCloudData[i].x,PointCloudData[i].y,PointCloudData[i].z,PointCloudData[i].intensity);//depend on your output pointcloud data information.
		printf("%lf  %lf  %lf",PointCloudData[i].x,PointCloudData[i].y,PointCloudData[i].z);
		cout<<endl;
	} 
	
}

	fclose(stdin);
	fclose(stdout);


return 0;
}
