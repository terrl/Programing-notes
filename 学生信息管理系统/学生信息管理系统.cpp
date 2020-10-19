#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct date  
					{
						int year;
						int month;
						int day;
					};
typedef struct student
{	
					char no[9];				//学生结构体
					char name[9];			
					char sex[3];			
					struct  date birthday;
					int score[4];				
}student;
student st[30];
void menu();
int input();
void output(int n);
void namearrange(int n);
void scorearrange(int n);
void scoreout(int n);
void information(int n);
void average(int n);
void sex(int n);
void file(int n);
int main()
{
	menu();
	return 0;
}
void menu()
{
	int num,n;
	input();
	n=input();
	printf("请选择菜单\n");
	printf("1.显示原始学生信息表\n");
	printf("2.按姓名递增排序\n");
	printf("3.显示按总分递减排序后学生信息\n");
    printf("4.按学号丶姓名查学生信息和平均分数\n");
	printf("5.各门课平均分数\n");
	printf("6.男女学生人数和总人数\n");
	printf("7.以文件方式显示排序后学生信息表\n");
	printf("8.退出\n");
	scanf("%d",&num);
	switch(num)
	{
	case 1:
		output(n);
		break;
	case 2:
		namearrange(n);
		break;
	case 3:
		scoreout(n);
		break;
	case 4:
		information(n);
		break;
	case 5:
		average(n);
		break;
	case 6:
		sex(n);
		break;
	case 7:
		file(n);
		break;
	case 8:
		return;
	default :
		printf("请在1~7中选择\n");
		menu();
	}
}

int input()
{
	int n,i=0;
	FILE *fp;
	fp=fopen("D:\\studf.txt","r");
	if(fp==0)                                       //输入
	{
		printf("file error!\n");
		exit(1);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%d%d%d%d%d%d%d",st[i].no,st[i].name,st[i].sex,&st[i].birthday.year,&st[i].birthday.month,&st[i].birthday.day,&st[i].score[0],&st[i].score[1],&st[i].score[2],&st[i].score[3]);
		i++;
	}
	fclose(fp);
	n=i;
	return n;
}
void output(int n)
{
	int i;
	printf("学号\t姓名\t性别\t\t生日    \t数学\t英语\tC语言\t总分\n");  //输出
	for(i=0;i<n;i++)
	{
		printf("%s\t%s\t%s\t   %d年%d月%d日 \t%d\t%d\t%d\t%d\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3]);
	}
}
void namearrange(int n)
{
	int i,k;
	student t;
	for (i=0;i<n-1;i++)
	{

		for (k=n-1;k>i;k--)
		{
			if(strcmp(st[k].name,st[k-1].name)<0)      //姓名+冒泡
			{
				t=st[k-1];
                st[k-1]=st[k];
				st[k]=t;
			}
		}
	}
}
void scorearrange(int n)
{
	int i,k,index;
	student t;
	for (i=0;i<=n;i++)
	{
		index=i;
		for (k=i+1;k<=n-1;k++)
		{
			if (st[k].score[3]>st[index].score[3])     //选择排序
				index=k;
			if (index!=i)
			{
				t=st[index];
                st[index]=st[i];
				st[i]=t;
			}
		}
	} 
	
}
void scoreout(int n)
{
	scorearrange(n);
	int i;
	printf("学号\t姓名\t性别\t\t生日    \t数学\t英语\tC语言\t总分\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%s\t%s\t   %d年%d月%d日 \t%d\t%d\t%d\t%d\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3]);
	}
}
void information(int n)
{
	int i,flag=0,item;
	double m;
	printf("请选择子菜单\n");
	printf("1.按学号查询\n");
	printf("2.按姓名查询\n");
	printf("3.返回主菜单\n");
	printf("4.退出\n");
	scanf("%d",&item);
	switch(item)
	{                               //信息
		char st1[10];
	case 1:
		printf("请输入待查询学号（如：01）\n");
		scanf("%s",&st1);
		for(i=0;i<n;i++)
		{
			if(strcmp(st[i].no,st1)==0)
			{
				flag=1;
				m=st[i].score[3]/3.0;
				printf("学号:%s 姓名:%s 性别:%s 生日:%d年%d月%d日 数学:%d 英语:%d C语言:%d 总分:%d 平均分：%.2f\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3],m);
			}
		}
			if(flag==0)
				printf("该学号不存在！\n");
				break;
	case 2:
		printf("请输入待查询学生姓名\n");
		scanf("%s",&st1);
		for(i=0;i<n;i++)
		{
			if(strcmp(st[i].name,st1)==0)
			break;
		}
		if(strcmp(st[i].name,st1)==0)
		{
			m=st[i].score[3]/3.0;
			printf("学号:%s 姓名:%s 性别:%s 生日:%d年%d月%d日 数学:%d 英语:%d C语言:%d 总分:%d 平均分：%.2f\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3],m);
		}
		else
			printf("该姓名不存在！\n");
			break;
	case 3:
		menu();
		break;
	case 4:
		return;
	default :
		printf("请在1~4中选择！\n");
		information(n);
	}
}
void average(int n)	
{
	double a=0,b=0,c=0,h,j,k;
		int i,m;
		for(i=0;i<n;i++)
		{
			a+=st[i].score[0];
			b+=st[i].score[1];
			c+=st[i].score[2];
		}
		h=a/n;
		j=b/n;
		k=c/n;                                                  //各科平均分
		printf("请输入查询科目代号\n");
		printf("1.数学\n");
	    printf("2.英语\n");
	    printf("3.C语言\n");
		scanf("%d",&m);
		switch(m)
		{
		case 1:
			printf("%.2f\n",h);
			break;
		case 2:
			printf("%.2f\n",j);
			break;
		case 3:
			printf("%.2f\n",k);
			break;
		}
}
void sex(int n)
{
	int i,j=0,k=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(st[i].sex,"m")==0)
			j++; 
		else
			k++;
	}                                  //查人数
	printf("男生：%d\n",j);
	printf("女生：%d\n",k);
	printf("总人数：%d\n",n);
}
void file(int n)
{
	int i;
	scorearrange(n);
	FILE *f;
	f=fopen("D:\\student arrange.txt","w");
	if(!f)
	{
		printf("file error!\n");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		fprintf(f,"%s %s %s %d %d %d %d %d %d %d\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3]);
	}
	fclose(f);
	f=fopen("D:\\student arrange.txt","r");
	if(!f)
	{
		printf("file error!\n");
		exit(1);
	}
	printf("学号\t姓名\t性别\t\t生日    \t数学\t英语\tC语言\t总分\n");
	for(i=0;i<n;i++)
	{
		fscanf(f,"%s%s%s%d%d%d%d%d%d%d",st[i].no,st[i].name,st[i].sex,&st[i].birthday.year,&st[i].birthday.month,&st[i].birthday.day,&st[i].score[0],&st[i].score[1],&st[i].score[2],&st[i].score[3]);
	    
	    printf("%s\t%s\t%s\t   %d年%d月%d日 \t%d\t%d\t%d\t%d\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3]);
	}
	fclose(f);
}



