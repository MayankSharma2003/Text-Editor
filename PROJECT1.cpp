#include<iostream>
#include<fstream>
#include<windows.h>
#include<mmsystem.h>
#include<stack>
using namespace std;
class Node
	{
		public:
		string data;
		class Node* next;
	};
stack<string> strlist;stack<int> poslist;
stack<string> strlist1;stack<int> poslist1;	
class insert
	{
		public:
		void insertData(Node** head,string str)
			{
				strlist.push(str);
				poslist.push(0);
				Node *node=new Node();
				Node* last=*head;
				node->data=str;
				node->next=NULL;
				if(*head==NULL)
					{
						*head=node;
						return;
					}
				while(last->next!=NULL)
					last=last->next;
				last->next=node;
				while(!strlist1.empty())
					{
						strlist1.pop();
						poslist1.pop();
					}
				return;
			}		
	};
class update
	{
		public:
		void updateData1(Node* head,string str,int line)
			{
				Node* temp=head;
				poslist.push(line);
              	while(line>1&&temp!=NULL)
              		{
               			temp=temp->next;
                    	line--;
                    }
                if(line!=1 || temp==NULL)
					{
						cout<<"---DATA DOES NOT EXIST--- ";
						return;
					}
				strlist.push(temp->data);
       			temp->data  = str;    
       			while(!strlist1.empty())
					{
						strlist1.pop();
						poslist1.pop();
					}
			}	
			void updateData2(Node* head,string str,string text)
			{
				Node* temp=head;
				int count=0,i=1,arr[100],line,k=0;
				while(temp!=NULL)
					{
						int found = temp->data.find(text);
						if(found!=-1 && (temp->data.length())==(text.length()))
							{
								arr[k++]=i;
								count++;			
							}
						i++;
						temp=temp->next;
					}
                if(count==0)
					{
						cout<<"---DATA DOES NOT EXIST--- ";
						return;
					}  
				if(k==1)
					{
						line=arr[0];
						poslist.push(line);
						Node* temp=head;
              			while(line>1&&temp!=NULL)
              				{
               					temp=temp->next;
                    			line--;
                    		}
                		if(line!=1 || temp==NULL)
							{
								cout<<"---DATA DOES NOT EXIST--- ";
								return;
							}
						strlist.push(temp->data);
       					temp->data  = str;
       					while(!strlist1.empty())
							{
								strlist1.pop();
								poslist1.pop();
							}
						return;  
					}		
				cout<<"Text found at Position : ";
				for(i=0;i<k;i++)
					{
						cout<<arr[i]<<" ";
					}
				cout<<"\nEnter the row number to update : ";
				cin>>line;
				for(i=0;i<k;i++)
					{
						if(line==arr[i])
							break;
					}
				if(i==k)
					{
						cout<<"\nVALUE DOES NOT MATCH...";
						return;
					}
				poslist.push(line);
				Node* temp1=head;
              	while(line>1&&temp1!=NULL)
          			{
               			temp1=temp1->next;
                    	line--;
                   	}
                if(line!=1 || temp1==NULL)
					{
						cout<<"---DATA DOES NOT EXIST--- ";
						return;
					}
				strlist.push(temp1->data);
   				temp1->data  = str;   
   				while(!strlist1.empty())
					{
						strlist1.pop();
						poslist1.pop();
					}
			}	
	};
class append
	{
		public:
		void appendData1(Node* head,string str,int line)
			{
				Node* temp=head;
				poslist.push(line);
              	while(line>1&&temp!=NULL)
              		{
               			temp=temp->next;
                    	line--;
                    }
                if(line!=1 || temp==NULL)
					{
						cout<<"---DATA DOES NOT EXIST--- ";
						return;
					}
				strlist.push(temp->data);
       			temp->data  = temp->data+str;    
       			while(!strlist1.empty())
					{
						strlist1.pop();
						poslist1.pop();
					}
			}
		void appendData2(Node* head,string str,string text)
			{
				Node* temp=head;
				int count=0,i=1,arr[100],line,k=0;
				while(temp!=NULL)
					{
						int found = temp->data.find(text);
						if(found!=-1 && (temp->data.length())==(text.length()))
							{
								arr[k++]=i;
								count++;			
							}
						i++;
						temp=temp->next;
					}
                if(count==0)
					{
						cout<<"---DATA DOES NOT EXIST--- ";
						return;
					}  
				if(k==1)
					{
						line=arr[0];
						poslist.push(line);
						Node* temp=head;
              			while(line>1&&temp!=NULL)
              				{
               					temp=temp->next;
                    			line--;
                    		}
                		if(line!=1 || temp==NULL)
							{
								cout<<"---DATA DOES NOT EXIST--- ";
								return;
							}
						strlist.push(temp->data);
       					temp->data  = temp->data+str;
       					while(!strlist1.empty())
							{
								strlist1.pop();
								poslist1.pop();
							}
						return;  
					}		
				cout<<"Text found at Position : ";
				for(i=0;i<k;i++)
					{
						cout<<arr[i]<<" ";
					}
				cout<<"\nEnter the row number to append : ";
				cin>>line;
				for(i=0;i<k;i++)
					{
						if(line==arr[i])
							break;
					}
				if(i==k)
					{
						cout<<"\nVALUE DOES NOT MATCH...";
						return;
					} 
				poslist.push(line);
				Node* temp1=head;
              	while(line>1&&temp1!=NULL)
          			{
               			temp1=temp1->next;
                    	line--;
                   	}
                if(line!=1 || temp1==NULL)
					{
						cout<<"---DATA DOES NOT EXIST--- ";
						return;
					}
				strlist.push(temp1->data);
   				temp1->data  = temp1->data+str;
				while(!strlist1.empty())
					{
						strlist1.pop();
						poslist1.pop();
					}   
			}
	};
class search
	{
		public:
		void searchData(Node* head,string str)
			{
				Node* temp=head;
				int i=1,count=0,pos=0;
				while(temp!=NULL)
					{
						pos=0;
						while((pos=temp->data.find(str,pos))!=-1)
							{
								cout<<"\nText found at line "<<i<<" and position "<<pos+1;
								pos=pos+str.size();
								count++;
							}
						i++;
						temp=temp->next;
					}
				if(count==0)
					{
						cout<<"!---TEXT NOT FOUND---!";
						return;
					}
			}
	};
class Delete
	{
		public:
		void deleteData1(Node** head,int line)
			{
				poslist.push((-line));
				Node* temp=(*head);
				Node* prev=new Node();
				if(temp->next==NULL&&line==1)
					{
						strlist.push(temp->data);
						(*head)=NULL;
						while(!strlist1.empty())
							{
								strlist1.pop();
								poslist1.pop();
							}
						return;
					}
				while(line>1&&temp!=NULL)
					{
						prev=temp;
						temp=temp->next;
						line--;
					}
				if(line!=1 || temp==NULL)
					{
						cout<<"---DATA DOES NOT EXIST--- ";
						return;
					}
				if(temp->next==NULL)
					{
						strlist.push(temp->data);
						prev->next=temp->next;
						while(!strlist1.empty())
							{		
								strlist1.pop();
								poslist1.pop();
							}
						return;
					}
				strlist.push(temp->data);
				temp->data=temp->next->data;
				temp->next=temp->next->next;
				while(!strlist1.empty())
					{
						strlist1.pop();
						poslist1.pop();
					}
			}
		void deleteData2(Node** head,string text)
			{
				Node* temp1=(*head);
				int arr[100];
				int i=1,count=0,k=0,line;
				while(temp1!=NULL)
					{
						int found = temp1->data.find(text);
						if(found!=-1 && (temp1->data.length())==(text.length()))
							{
								count++;
								arr[k++]=i;
							}
						i++;
						temp1=temp1->next;
					}
				if(count==0 )
					{
						cout<<"!---TEXT NOT FOUND---!";
						return;
					}
				if(k==1)
					{
						line=arr[0];
						poslist.push((-line));
						Node* temp=(*head);
						Node* prev=new Node();
						if(temp->next==NULL&&line==1)
							{
								strlist.push(temp->data);
								(*head)=NULL;
								while(!strlist1.empty())
									{			
										strlist1.pop();
										poslist1.pop();
									}
								return;
							}
						while(line>1&&temp!=NULL)
							{
								prev=temp;
								temp=temp->next;
								line--;
							}
						if(line!=1 || temp==NULL)
							{
								cout<<"---DATA DOES NOT EXIST--- ";
								return;
							}
						if(temp->next==NULL)
							{
								strlist.push(temp->data);
								prev->next=temp->next;
								while(!strlist1.empty())
									{
										strlist1.pop();
										poslist1.pop();
									}
								return;
							}
						strlist.push(temp->data);
						temp->data=temp->next->data;
						temp->next=temp->next->next;
						while(!strlist1.empty())
							{
								strlist1.pop();
								poslist1.pop();
							}
						return;
					}
				cout<<"Text found at Position : ";
				for(i=0;i<k;i++)
					{
						cout<<arr[i]<<" ";
					}
				cout<<"\nEnter the row number to delete : ";
				cin>>line;
				for(i=0;i<k;i++)
					{
						if(line==arr[i])
							break;
					}
				if(i==k)
					{
						cout<<"\nVALUE DOES NOT MATCH...";
						return;
					}
				poslist.push((-line));
				Node* temp=(*head);
				Node* prev=new Node();
				if(temp->next==NULL&&line==1)
					{
						strlist.push(temp->data);
						(*head)=NULL;
						while(!strlist1.empty())
							{	
								strlist1.pop();
								poslist1.pop();
							}
						return;
					}
				while(line>1&&temp!=NULL)
					{
						prev=temp;
						temp=temp->next;
						line--;
					}
				if(line!=1 || temp==NULL)
					{
						cout<<"---DATA DOES NOT EXIST--- ";
						return;
					}
				if(temp->next==NULL)
					{
						strlist.push(temp->data);
						prev->next=temp->next;
						while(!strlist1.empty())
							{		
								strlist1.pop();
								poslist1.pop();
							}
						return;
					}
				strlist.push(temp->data);
				temp->data=temp->next->data;
				temp->next=temp->next->next;
				while(!strlist1.empty())
					{
						strlist1.pop();
						poslist1.pop();
					}
			}	
	};
class display
	{
		public:
		void printData(Node* head)
			{
				Node* temp=head;
				cout<<endl;
				while(temp!=NULL)
					{
						cout<<temp->data<<endl;
						temp=temp->next;
					}
			}
	};
class undo
	{
		public:
		void undoData(Node **head)
			{
				if(poslist.top()==0)
					{
						Node* temp = (*head);
						if(temp->next==NULL)
							{		
								strlist1.push(temp->data);
								poslist1.push(0);
								(*head)=NULL;
								poslist.pop();
								strlist.pop();
								return;
							}
						while(temp->next->next!=NULL)
							{
								temp=temp->next;
							}
						strlist1.push(temp->next->data);
						poslist1.push(0);
						temp->next=temp->next->next;
						poslist.pop();
						strlist.pop();
						return;
					}
				if(poslist.top()>0)
					{
						string str=strlist.top();
						int line=poslist.top();
						Node *temp=(*head);
						poslist1.push(line);
						while(line>1)
							{
								temp=temp->next;
								line--;
							}
						strlist1.push(temp->data);
						temp->data=str;
						strlist.pop();
						poslist.pop();
						return;
					}
				else
					{
						Node* temp=(*head);
						Node* prev=new Node();
						int line = -(poslist.top());
						poslist1.push((-line));
						if(line==1)
						{
							Node* node=new Node();
							strlist1.push(strlist.top());
							node->data  = strlist.top();     
    						node->next = (*head);   
    						(*head)    = node;
    						poslist.pop();
    						strlist.pop();
    						return;
    					}
    					while(line!=1)
    						{
    							prev=temp;
    							temp=temp->next;
    							line--;
							}
						if(temp==NULL)
							{
								Node* node=new Node();
								strlist1.push(strlist.top());
								node->data=strlist.top();
								node->next=NULL;
								prev->next=node;
								strlist.pop();
								poslist.pop();
								return;
							}
						else
							{
								Node* node=new Node();
								strlist1.push(strlist.top());
								node->data=strlist.top();
								node->next=temp;
								prev->next=node;
								strlist.pop();
								poslist.pop();
								return;
							}
					}
			}
	};
class redo
	{
		public:
		void redoData(Node **head)
			{
				if(poslist1.top()==0)
					{
						poslist.push(0);
						Node* temp=(*head);
						if(temp==NULL)
							{
								strlist.push(strlist1.top());
								Node* node=new Node();
								node->data  = strlist1.top();     
    							node->next = (*head);   
    							(*head)    = node;
    							strlist1.pop();
    							poslist1.pop();
    							return;
							}
						while(temp->next!=NULL)
							{
								temp=temp->next;
							}
						strlist.push(strlist1.top());
						Node* node=new Node();
						node->data  = strlist1.top();     
    					node->next = NULL;
    					temp->next=node;
    					strlist1.pop();
    					poslist1.pop();
    					return;
					}
				if(poslist1.top()>0)
					{
						string str=strlist1.top();
						int line=poslist1.top();
						poslist.push(line);
						Node *temp=(*head);
						while(line>1)
							{
								temp=temp->next;
								line--;
							}
						strlist.push(temp->data);
						temp->data=str;
						strlist1.pop();
						poslist1.pop();
						return;
					}
				else
					{
						string str=strlist1.top();
						int line=(-(poslist1.top()));
						poslist.push((-line));
						Node* temp=(*head);
						Node* prev=new Node();
						if(temp->next==NULL&&line==1)
							{
								strlist.push(strlist1.top());
								strlist1.pop();
    							poslist1.pop();
								(*head)=NULL;
								return;
							}
						while(line>1&&temp!=NULL)
							{
								prev=temp;
								temp=temp->next;
								line--;
							}
						if(temp->next==NULL)
							{
								strlist.push(strlist1.top());
								strlist1.pop();
    							poslist1.pop();
								prev->next=temp->next;
								return;
							}
						strlist.push(strlist1.top());
						temp->data=temp->next->data;
						temp->next=temp->next->next;
						strlist1.pop();
    					poslist1.pop();
    					return;
					}
			}	
	};
class store
	{
		public:
		void storeData(Node* head)
			{
				char c;
				fstream out;
				ofstream out1("D:\\data.txt");
				string name;
				cout<<"\nEnter the name of file : ";
				cin>>name;
				out.open(name.c_str(),ios::out);
				Node *temp=head;
				while(temp!=NULL)
					{
						out<<temp->data;
						out<<endl;
						out1<<temp->data;
						out1<<endl;
						temp=temp->next;
					}
			}
	};
int main()
	{ 
    	int choice,option,line,i,x;
    	string str,text;                         
    	Node* head=NULL;
            cout<<"* * * * * * * * * * * * * * * * * * *"<<endl;
            cout<<"*       TEXT EDITOR USING C++       *"<<endl;
            cout<<"* * * * * * * * * * * * * * * * * * *"<<endl<<endl;
    do
        {
        	cout<<"\n* * * * * * *OPTION LIST* * * * * * *"<<endl;
        	cout<<"*                                   *"<<endl;
            cout<<"*        1. INSERT TEXT             *"<<endl;
            cout<<"*        2. UPDATE TEXT             *"<<endl;
            cout<<"*        3. APPEND TEXT             *"<<endl;
            cout<<"*        4. SEARCH DATA             *"<<endl;
            cout<<"*        5. DELETE DATA             *"<<endl;
            cout<<"*        6. DISPLAY DATA            *"<<endl;
            cout<<"*        7. UNDO DATA               *"<<endl;
            cout<<"*        8. REDO DATA               *"<<endl;
            cout<<"*        9. STORE DATA PERMANENTLY  *"<<endl;
            cout<<"*                                   *"<<endl;
            cout<<"* * * * * * * * * * * * * * * * * * *"<<endl;
            cout<<"\n-->Enter choice as per your need : ";
            cin>>choice;
            switch(choice)
                {
                    case 1:
                    	{
                    		cout<<"\nType the text you what insert : ";
                    		getchar();
                    		getline (cin, str);
                    		insert element;
                    		element.insertData(&head,str);
                    		i=1;
                    		break;
                   		}
                    case 2:
                    	{
							if(head==NULL)
								{
									cout<<"\n!-----LIST IS EMPTY-----!";
									break;
								}	
							cout<<"UPDATE OPTION : \n1.Using line number\n2.Using text";
							cout<<"\n\nCHOOSE 1 or 2 : ";
							cin>>x;
							if(x==1)
								{
                    				cout<<"\nWhich line you want to UPDATE : ";
                    				cin>>line;
                    				cout<<"\nType the text you what UPDATE: ";
                    				getchar();
                    				getline (cin, str);
                   					update element;
                    				element.updateData1(head,str,line);
                    				i=1;
                    				break;
                    			}
                    		else if (x==2)
                    			{
 									cout<<"\nEnter the text (To be searched) : ";
                    				getchar();
                    				getline(cin,text);
                    				cout<<"\nType the text you what UPDATE: ";
                    				getline (cin, str);
                   					update element;
                    				element.updateData2(head,str,text);
                    				i=1;
                    				break;                   				
								}
                    		else
                    			cout<<"WRONG INPUT";
                    		break;
                    	}
                    case 3:
                    	{
                    		if(head==NULL)
								{
									cout<<"\n!-----LIST IS EMPTY-----!";
									break;
								}
							cout<<"APPEND OPTION : \n1.Using line number\n2.Using text";
							cout<<"\n\nCHOOSE 1 or 2 : ";
							cin>>x;
							if(x==1)
								{
									cout<<"\nWhich line you APPEND extra text : ";
									cin>>line;
									cout<<"\nType the text you what APPEND : ";
                    				getchar();
                    				getline (cin, str);
                   					append element;
                    				element.appendData1(head,str,line);
                    				i=1;
                    				break;
								}
							else if(x==2)
								{
									cout<<"\nEnter the text (To be searched): ";
									getchar();
									getline(cin,text);
									cout<<"\nType the text you what APPEND : ";
                    				getline (cin, str);
                   					append element;
                    				element.appendData2(head,str,text);
                    				i=1;
                    				break;
								}
						  	else
                    			cout<<"WRONG INPUT";
                    		break;
                    	}
                    case 4:
                    	{
                    		if(head==NULL)
								{
									cout<<"\n!-----LIST IS EMPTY-----!";
									break;
								}
							cout<<"\nEnter the string you want to SEARCH : ";
							getchar();
                    		getline (cin, str);
                    		search element;
                    		element.searchData(head,str);
                    		break;
						}
					case 5:
						{
							if(head==NULL)
								{
									cout<<"\n!-----LIST IS EMPTY-----!";
									break;
								}
							cout<<"DELETE OPTION : \n1.Using line number\n2.Using text";
							cout<<"\n\nCHOOSE 1 or 2 : ";
							cin>>x;
							if(x==1)
								{
									cout<<"\nEnter the line you want to DELETE : ";
									cin>>line;
									Delete element;
									element.deleteData1(&head,line);
									i=1;
									break;
								}
							else if (x==2)
								{
									cout<<"\nEnter the text (To be DELETE) : ";
									getchar();
									getline(cin,text);
									Delete element;
									element.deleteData2(&head,text);
									i=1;
									break;
								}
							else
								cout<<"WRONG INPUT";
							break;
						}
					case 6:
						{
							if(head==NULL)
								{
									cout<<"\n!-----LIST IS EMPTY-----!";
									break;
								}
							display element;
							element.printData(head);
							break;
						}
                   	case 7:
                   		{
                   			if(poslist.empty())
                   				{
                   					cout<<"\n!-----NO TASK TO PERFORM-----!";
									break;
								}
							undo element;
							element.undoData(&head);
							cout<<"'UNDO' task done";
							i=0;
                   			break;
					    }
					case 8:
						{
							if(i!=0 || poslist1.empty()) 
								{
									cout<<"\n!-----NO TASK TO PERFORM----!";
									break;
								}
							redo element;
							element.redoData(&head);
							cout<<" 'REDO' TASK DONE ";
							break;
						}
					case 9:
						{
							if(head==NULL)
								{
									cout<<"\n!-----LIST IS EMPTY-----!";
									break;
								}
							store element;
							element.storeData(head);
							cout<<"\n!------DATA STORED SUCCESSFULLY------!";
							cout<<"\n\nDo you want to open the file(YES/1) or (NO/2) : ";
							cin>>x;
							if(x==1)
								ShellExecute (NULL,"open","D:\\data.txt", NULL ,  NULL, SW_NORMAL);
							break;
						}
				    default: 
                        cout<<"!----WRONG INPUT(Choose from above option)----!";
                }
            cout<<"\n\nPress '1' to continue otherwise PRESS ANY OTHER key -> ";
            cin>>option;
        }
    while(option==1);  				
   return 0;
}
