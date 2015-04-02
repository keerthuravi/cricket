#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
class bst
{
private:
struct node
{
	node *left;
	node *right;
	int data1;
	
	long int phone;
	string comment1,comment2,comment3;
	string c_name;
};
node * root;

	int rate1,rate2,rate3,rate4,rate5,rate6,rate7,rate8,rate9;
void remove1(int x,node *&t);
void update1(int id,node *&t);
void search1(int x,node *&t);
public:
	bst()
	{
		root=NULL;
		rate1=0;rate4=0;rate7=0;
		rate2=0;rate5=0;rate8=0;
		rate3=0;rate6=0;rate9=0;
	}
	bool isempty() const
	{
		return root==NULL;
	}
    friend void rating(bst&);
	void order(node *);
	void insert(int,string,long int,string,string,string);
	void display();
	void update(int id)
	{
		update1(id,root);
	}
	void remove(int x)
	{
		remove1(x,root);
	}
	void search(int x)
	{
		search1(x,root);
	}
	void from_file(bst &b)
{
	int data1;
	long int phone;
	string comment1,comment2,comment3,c_name;
	
	ifstream f1("cricket.xls");
	if(f1.is_open())
	{
		while(!f1.eof())
		{
			f1>>data1>>c_name>>phone>>comment1>>comment2>>comment3;
			b.insert(data1,c_name,phone,comment1,comment2,comment3);
		}
	}
}
void fwrite(int ,string ,long int ,string ,string ,string);

};


void bst::fwrite(int ID,string NAME,long int CONTACT_NUMBER,string COMMENT1,string COMMENT2,string COMMENT3)
{
	ofstream f1("cricket.xls",ios::app);
    f1<<ID<<"\t"<<NAME<<"\t"<<CONTACT_NUMBER<<"\t"<<COMMENT1<<"\t"<<COMMENT2<<"\t"<<COMMENT3<<endl;
}
void bst::insert(int d1,string d,long int p,string d2,string d3,string d4)
{
	node *t=new node;
	node *head;
	t->data1=d1;
	t->c_name=d;
	t->phone=p;
    t->comment1=d2;
	t->comment2=d3;
	t->comment3=d4;	
	t->left=NULL;
	t->right=NULL;
	head=NULL;
	 if(isempty())
	 {
	 	root=t;
	 }
	 else
	 {
	 	node *temp;
	 	temp=root;
	 	while(temp)
	 	{
	 		head=temp;
	 		if(t->data1>temp->data1)
	 		temp=temp->right;
	 		else
	 		temp=temp->left;
	 	}
	 	if(t->data1<head->data1)
	 	head->left=t;
	 	else
	 	head->right=t;
	 }
}
void bst::display()
{
	order(root);	
}

void bst::order(node *o)
{
	if(o!=NULL)
	{
		if(o->left)
			order(o->left);
			cout<<"\t\t\t"<<o->data1<<"\n";
			cout<<"\t\t\t"<<o->c_name<<"\n";
			cout<<"\t\t\t"<<o->phone<<"\n";
			cout<<"\t\t\tT20        :  ";
			cout<<o->comment1<<"\n";
			if(o->comment1=="like")
				rate1++;
			if(o->comment1=="unlike")
				rate2++;
			if(o->comment1=="nocomment")
				rate3++;
			
			cout<<"\t\t\tODI        :  ";
			cout<<o->comment2<<"\n";
			if(o->comment2=="like")
				rate4++;
			if(o->comment2=="unlike")
				rate5++;
			if(o->comment2=="nocomment")
				rate6++;
			
			cout<<"\t\t\tTEST MATCH :  ";
			cout<<o->comment3<<"\n";
			cout<<"...............................................................................";
			if(o->comment3=="like")
				rate7++;
			if(o->comment3=="unlike")
				rate8++;
			if(o->comment3=="nocomment")
				rate9++;
			
			cout<<"\n";
		if(o->right)
			order(o->right);
	}
		else	
			cout<<"NO FEEDBACK";
				
}
void bst::search1(int x,node *&t)
{
	if(t==NULL)
	{
		cout<<"ID Not Found"<<endl;
	}
	else 
	{
		if(x<t->data1)
		{
			search1(x,t->left);
		}
		else if(x>t->data1)
		{
			search1(x,t->right);
		}
		else
		{
			cout<<"\n \t\t\t  Searched User's Details:"<<endl;
		cout<<"\t\t\tName       :"<<t->c_name<<endl;
		cout<<"\t\t\tContact No :"<<t->phone<<endl;
		cout<<"\t\t\tT20        :"<<t->comment1<<endl;
		cout<<"\t\t\tODI        :"<<t->comment2<<endl;
	    cout<<"\t\t\tTEST MATCH :"<<t->comment3<<endl;
      }
	}
}
void bst::remove1(int x,node *&t)
{
	struct node *d;
	if(t==NULL)
	{
		return;
		
	}
	if(x<t->data1)
		remove1(x,t->left);
	else if(x>t->data1)
		remove1(x,t->right);
	else if(t->left==NULL&&t->right==NULL)
	{
	d=t;
	free(d);
	t=NULL;
		cout<<"Data Deleted";
	}
	else if(t->left==NULL)
	{
	d=t;
	t=t->right;
	free(d);
	cout<<"FEEDBACK DELETED";
	
	}
	else if(x==t->data1)
	{
		d=t;
		free(d);
	}
	else if(t->right==NULL)
	{
		d=t;
		t=t->left;
		free(d);
		cout<<"FEEDBACK DELETED";
	}
	else 
		cout<<"DATA NOT FOUND";
}
void bst::update1(int id,node *&t)
{
	string newcmd;
	string br;
	if(t!=NULL)
	{
		if(id<t->data1)
				update1(id,t->left);
		else if(id>t->data1)
			     update1(id,t->right);
		else if(id=t->data1)
		{       cout<<"Which Form Of Cricket Do You Want To Update";cout<<endl;
				cout<<endl;
		         cin>>br;
		         cout<<endl;
		     	cout<<"Enter New Comment:";
		     	cin>>newcmd;
		    if(br=="t20")
		    	t->comment1=newcmd;
		    if(br=="odi")
		    	t->comment2=newcmd;
			if(br=="test match")
		    	t->comment3=newcmd;	
		     	cout<<"Your comment is updated successfully."<<endl;
				cout<<"Enter display to see the change in your feedback."<<endl;
		}
	
	}
	else 
		{
			cout<<" Enter Valid ID "<<endl;
		}
}
void rating(bst &b)
{
	cout<<endl<<endl;
	cout<<"Feedback for t20 ";
	cout<<endl<<endl;
	cout<<"Likes       : "<<b.rate1;
	cout<<endl;
	cout<<"Unlikes     : "<<b.rate2;
	cout<<endl;
	cout<<"No comments : "<<b.rate3;
	cout<<"\n\n";
	
	cout<<"Feedback for odi ";
	cout<<endl<<endl;
	cout<<"Likes       : "<<b.rate4;
	cout<<endl;
	cout<<"Unlikes     : "<<b.rate5;
	cout<<endl;
	cout<<"No comments : "<<b.rate6;
	cout<<"\n\n";
	
	cout<<"Feedback for test match ";
	cout<<endl<<endl;
	cout<<"Likes       : "<<b.rate7;
	cout<<endl;
	cout<<"Unlikes     : "<<b.rate8;
	cout<<endl;
	cout<<"No comments : "<<b.rate9;
	cout<<endl;
	
	
}
main()
{
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t *********************************"<<endl;
	cout<<"\t\t\t * WELCOME CRICKET FEEDBACK SITE *"<<endl;
	cout<<"\t\t\t *********************************"<<endl;
	bst obj;
	int choice,x,id;
	long int p_no;
	string up_str,nm;
	string y,z,w;
	int a,g;
	while(1)
	{
		cout<<endl;
		cout<<endl;
		cout<<"\t\t\t\t1)ADDING FEEDBACK"<<endl<<endl;
		cout<<"\t\t\t\t2)TO DISPLAY FEEDBACK"<<endl<<endl;
		cout<<"\t\t\t\t3)SEARCH THE FEEDBACK"<<endl<<endl;
		cout<<"\t\t\t\t4)TO DELETE FEEDBACK"<<endl<<endl;
		cout<<"\t\t\t\t5)UPDATION"<<endl<<endl;
		cout<<"\t\t\t\t6)RATING OF FEEDBACK"<<endl<<endl;
		cout<<"\t\t\t\t7)EXIT"<<endl<<endl;
		cout<<"________________________________________________________________________________";
		cout<<endl;
	cout<<"Enter Your Choice:";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"Enter id:";
			cout<<endl;
			cin>>x;
			cout<<"Enter Your Name:";
			cout<<endl;
			cin>>nm;
			cout<<"Enter Contact No:";
			cout<<endl;
			cin>>p_no;
			cout<<"Enter Your Status for";
			cout<<endl;
			cout<<"T20        :";
			cin>>w;
			cout<<endl;
			cout<<"ODI        :";
			cin>>y;
			cout<<endl;
			cout<<"TEST MATCH :";
			cin>>z;
		    obj.insert(x,nm,p_no,w,y,z);
		    	obj.fwrite(x,nm,p_no,w,y,z);
			break;
		case 2:
			
			cout<<"\n\t\t\t\t User Details:"<<endl;
			cout<<endl;
			cout<<endl;
			obj.display();
			break;
		case 3:
			cout<<"\n Enter ID :"<<endl;
			cin>>id;
			obj.search(id);
			break;
		case 4:
			cout<<" Enter ID to be deleted:"<<endl;
			cin>>a;
			obj.remove(a);
			break;
		case 5:
			cout<<" Enter Your ID:";
			cin>>id;
			obj.update(id);
			break;
		case 6:
			cout<<" Rating For Your Feedback:";
			cout<<"\n\n";
			rating(obj);
			break;
		case 7:
			exit(0);
		default:
			cout<<"\n Enter Proper Choice"<<endl;
			break;
	}
	}

	getch();
	return 0;
	
}


