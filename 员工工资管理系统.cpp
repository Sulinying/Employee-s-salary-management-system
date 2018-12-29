#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstring>
#define MIND_LINE 15		//文字居中打印的行数
#define MIND_SPACE 40		//文字居中打印的列数
#define MAX_LINE   30		//界面的最大显示行数
using namespace std;
int Count=5;
struct Worker
{
	char name[20];
	char sex[20];
	char num[20];
    float salary;
};
Worker w[20]=
{ { "ZhangLi", "M", "2018100", 3000},
  {"Wangfang", "F", "2018101", 2500},
  {"zhaoqiang", "M","2018102", 5200},
  {"Xiaohong","F","2018103",3200},
  {"Zegui","M","2018104",4800}} ;
void setdata();
void PrintEnter(int Line);
void PrintSpace(int Space);
void WelcomeMenu();
void author(); 
void Menu();
void Back();
void Choose();
void Showdata1();
void change_salary (float a[],float b[]) ;      //换算税金和应发工资
void sort(Worker,int n);                        //按员工工资排序 
void Showdata2(float a[],float b[]);
int main()
{
	//int Count=3;
	WelcomeMenu();
	author();
	Menu();
	Choose();
} 
void WelcomeMenu()
{
	PrintEnter(MIND_LINE);
	PrintSpace(MIND_SPACE);
    cout<<"欢迎来到员工工资管理系统！"<<endl;
	getchar(); 
}
void author()
{
	cout<<setw(40)<<"制作人："<<endl;
	cout<<setw(45)<<"姓名\t"<<"班级\t"<<"学号\t\t"<<"时间\t"<<endl;
	cout<<setw(45)<<"屈倩倩\t"<<"1806\t"<<"20181003057\t"<<"2018.12.28\t"<<endl;
	cout<<setw(45)<<"施安琪\t"<<"1806\t"<<"20181003058\t"<<"2018.12.28\t"<<endl; 
	cout<<setw(45)<<"苏琳莹\t"<<"1806\t"<<"20181003059\t"<<"2018.12.28\t"<<endl;
	getchar(); 
}
void PrintEnter(int Line)
{
    for (int i = 0; i < Line; i++) cout<<endl;
}
void PrintSpace(int Space)
{
	for (int i = 0; i < Space; i++) cout<<" ";
}
void Menu()
{
	system("cls");
	PrintEnter(7);
	PrintSpace(30);
	cout << "**********************************************" << endl;
    cout << "                              ****    欢迎使用此员工工资管理系统        ****" << endl;
    cout << "                              ****          1.查看当前员工              ****" << endl;
    cout << "                              ****          2.添加新的员工              ****" << endl;
    cout << "                              ****          3.修改员工信息              ****" << endl;
    cout << "                              ****          4.删除员工信息              ****" << endl;
    cout << "                              ****          5.按工号查询员工工资        ****" << endl;
    cout << "                              ****          6.按姓名查询员工工资        ****" << endl;
    cout << "                              ****          7.按工资排序                ****" << endl;
    cout << "                              ****          8.查看总实发工资和平均工资  ****" << endl;
    cout << "                              ****          9.退出系统                  ****" << endl;
    cout << "                              **********************************************" << endl;
}
void Back()
{
    cout << "按Enter键返回主菜单";
    getchar();
    Menu();
}
void Showdata1()
{
	int i=0;
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"                               *职工工资信息表*                               "<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"   |姓 名|       |性别|          |工号|                |工资|"<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    for(i=0;i<20;i++)
    cout<<setw(10)<<w[i].name<<setw(10)<<w[i].sex<<setw(20)<<w[i].num<<setw(20)<<w[i].salary<<endl;
    getchar();
}
void Showdata2(float a[],float b[])
{
	int i=0;
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"                               *职工工资信息表*                               "<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"   |姓 名|       |性别|          |工号|                |工资|"<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    for(i=0;i<20;i++)
    cout<<setw(10)<<w[i].name<<setw(10)<<w[i].sex<<setw(20)<<w[i].num<<setw(20)<<w[i].salary<<endl;
    getchar();
}
void add (float a[],float b[])                                    //按不同税率计算实发工资，并计算 总实发工资 和 平均工资 
{
	float add=0;
    for(int i=0;i<Count;i++)
    {
        if(w[i].salary<1000)                           //按不同税率计算实发工资
       {
            b[i] = 0 ;
            a[i] = w[i].salary ;
        }
        if( ( w[i].salary<4999) && ( w[i].salary>=1000) )
        {
            b[i] =  w[i].salary*0.05 ;
            a[i]=  w[i].salary - b[i] ;
        }
        if( w[i].salary>=5000)
        {
            b[i] =  w[i].salary*0.1 ;
            a[i] = w[i].salary- b[i] ;
        }
    }
    for(int i=0;i<Count;i++)
        add=add+a[i];
    cout<<"总实发工资为："<<add<<endl;
    cout<<"平均工资为："<<add/Count<<endl; 
}
void sort(Worker w[],int n)                   
{
	int i,j,t1;
	char t2[20],t3[20];
	char t4[20];
	for(i=0;i<n-1;i++)
	   for(j=0;j<n-1;j++)
	      if(w[j].salary>w[j+1].salary)
		  {
		  	t1=w[j].salary;
			strcpy(t2,w[j].name);
			strcpy(t3,w[j].num);
			strcpy(t4,w[j].sex);
		  	w[j].salary=w[j+1].salary;
			strcpy(w[j].name,w[j+1].name);
			strcpy(w[j].num,w[j+1].num);
			strcpy(w[j].sex,w[j+1].sex);
		  	w[j+1].salary=t1;
			strcpy(w[j+1].name,t2);
			strcpy(w[j+1].num,t3);
			strcpy(w[j+1].sex,t4);
		   } 
}
void Choose()
{

	int i,e;
	int h=1; 
	int Choose;
	char name1[10];
	char num1[10];
	char num2[10];
	char num3[10];
	float pay_out[20];
    float true_salary[20];
	while(h>0)
	{
		cout<<"请输入您想查看的内容相对应的数字："; 
	    cin>>Choose;
	    switch(Choose)
	    {
		    case 1:
			    system("cls");                                  //查看当前信息 
			    Showdata1();
			    Back();
			    break;
			    
		    case 2:                                               //添加员工信息 
		        system("cls");
		        i=0; 
		        while((w[i].name)[0]!='\0' && i<20)               //找列表空的地方
		        {i++;}
	            if((w[i].name)[0]=='\0')                         //找到列表空的地方
	            {
	            	cout<<"输入你想添加的员工姓名、性别、工号和工资："<<endl;
	                cin>>name1;                                   //添加员工信息 
					cin>>w[i].sex;
				    cin>>num1;
				    cin>>w[i].salary;
					strcpy(w[i].name, name1);
					strcpy(w[i].num, num1);
				    cout<<"添加成功！"<<endl;
				    Count++;
	                cout<<setw(10)<<w[i].name<<setw(10)<<w[i].sex<<setw(10)<<w[i].num<<setw(10)<<w[i].salary<<endl;
	            } 
	            else                                               // 如果到最后都不是空的，则人员已满
				cout<<"人员已满"<<endl;
			    getchar();
                Back();
                break;       
				                        
			case 3:                                                    //修改员工信息 
				system("cls");
				cout<<"请输入要修改的员工工号："<<endl;
				cin>> num2;
				for(i=0; i<20; i++)
					{					
				        if(strcmp(w[i].num, num2)==0)                   //查找要修改的员工 
				        {
				        cout<<"修改员工  "<<endl;
					    cout<<setw(10)<<w[i].name<<setw(10)<<w[i].sex<<setw(20)<<w[i].num<<setw(20)<<w[i].salary<<endl;
					    cout<<"确认修改请按1,返回主菜单请按任意键"<<endl;                //确认是否修改他的 
					    cin>> e;
					    if(e==1)                                  
				       	{
						cout<<"请依次输入新的姓名、性别、工号、工资："<<endl;  //修改信息 
						cin>>name1;
						cin>> w[i].sex;
						cin>>num1;
						cin>>w[i].salary;
						strcpy(w[i].name, name1);
			            strcpy(w[i].num, num1);
			            cout<<"修改成功！"<<endl;
			            getchar();
			            Back();   
				       	}
				       	else Back(); 
						break;
						}
						if(i==19)                                      //查找不到对应的员工 
					    {
					    cout<<"查无此员工！"<<endl;
						getchar();
                        Back();
					    }
					}break;
					
			case 4:                                                  //删除员工信息 
				system("cls");
				cout<<"请输入你要删除的员工工号："<<endl;
				cin>>num3;
				for(i=0; i<20; i++)
				{
				if(strcmp(w[i].num, num3)==0)                     //查找要删除的员工 
				{
				    cout<<"删除员工  "<<endl;
					cout<<setw(10)<<w[i].name<<setw(10)<<w[i].sex<<setw(20)<<w[i].num<<setw(20)<<w[i].salary<<endl;
					cout<<"确认删除请按1,返回主菜单请按任意键"<<endl;              //确认是否删除他 
					cin>> e;
					if(e==1)                                  //删除该员工 
					{
					memset(&w[i], 0, sizeof(w[i]));
					cout<<"删除成功！"<<endl;
					getchar();
					Back();
					}
					else Back(); 
				    break;
				}
				if(i==19)                                        //查找不到对应的员工 
				{
				cout<<"查无此员工！"<<endl;
				getchar();
				Back();  
				}
				}break;
				    
			case 5:                                                   //按职工号查询员工的工资 
				{
			    system("cls");                                       
                int p=0 ;
                int i;
	            char number[20] ; 
                cout << "\n输入你要查询的职工号:" ;            
                cin>>number;
                for (i=0;i<Count;i++)                              
                {
					if((strncmp(number,w[i].num,20))==0)
                    {
					cout << "\n找到了!\n" ;
                    cout<<number<<'\t'<<w[i].salary<<endl;
                    p=1;
                    getchar();
                    Back();
                    break; 
                    }
                }
                if(p==0)
                {
                cout << "\n没有这个工号!\n" ;                     //查找不到对应的员工 
                getchar();Back();
                }
		        }break; 
		        
           case 6:                                                    //按姓名查找员工的工资 
				{
				system("cls");
				int p=0;
                int i;
                char find_name[20] ;
                cout << "\n输入你要查询的职工姓名:" ;
                cin>>find_name;
                for (i=0;i<Count;i++)
                {
					if((strncmp(find_name,w[i].name,20))==0)
                    {
					cout << "\n找到了!\n" ;                     
                    cout<<find_name<<'\t'<<w[i].salary<<endl;
                    p=1;
                    getchar();
                    Back();
                    break;
                    }
                }
                if(p==0)
                {
				cout << "\n没有这个员工!\n" ;                   //查找不到对应的员工 
                getchar();
                Back();
				}
			    }break;
			    
            case 7:                                                  //把员工按工资排序 ，并展示员工信息 
            	system("cls");    
                sort(w,Count);
                Showdata2(true_salary,pay_out);
                getchar();
                Back();
                break; 
				
			case 8:                                                  //查看当前的总实发工资和平均工资
			    system("cls");
				add(true_salary,pay_out);
			    getchar();
			    Back();
 			    break;
 			       
 		    case 9:
			    cout<<"已成功退出"<<endl;
				h=0;break;
				   
			default:
			    cout<<"输入数字不在0~9内"<<endl;                                                //退出系统 
			    getchar();
			    Back();
 			    break;
       }
	}
} 
		

        
	


