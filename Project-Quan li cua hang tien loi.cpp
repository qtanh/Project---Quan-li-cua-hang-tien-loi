#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int size =0;
int transCount=0;
typedef struct DateOfTransactionExp{
	int dayExp;
	int monthExp;
	int yearExp;
};
typedef struct DateOfTransactionImp{
	int dayImp;
	int monthImp;
	int yearImp;
};
typedef struct Transaction{
	char transIdImp[20];
	char transIdExp[20];
	int imp;
	int exp;
	DateOfTransactionImp doti;
	DateOfTransactionExp dote;
};
typedef struct Product{
	char productId[10];
	char name[50];
	char unit[10];
	int quantity;
	int status;
	Transaction trans;
};
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void mainMenu(){
	printf("\n||===================Gocery store management systems==================||\n");
	printf("||==============================1.Products============================||\n");
	printf("||=========================2.Import and export========================||\n");
	printf("||===============================3.Exit===============================||\n");
	printf("||====================================================================||\n");
};
void assiMenu(){
	printf("\n||=============Gocery store management systems-Product============||\n");
	printf("||=======================1.Add more products======================||\n");
	printf("||=======================2.Update information=====================||\n");
	printf("||=======================3.Manage status==========================||\n");
	printf("||=======================4.Search=================================||\n");
	printf("||=======================5.Print out the list=====================||\n");
	printf("||=======================6.Arrange list===========================||\n");
	printf("||=======================7.Back===================================||\n");
	printf("||================================================================||\n");
}
void subMenu(){
	printf("\n||=========Gocery store management systems-Import and export======||\n");
	printf("||================1.Trading of import and export==================||\n");
	printf("||================2.History of import and export==================||\n");
	printf("||================3.Back==========================================||\n");
	printf("||================================================================||\n");
}
void initializeProducts(Product *pro) {
    Product initialProducts[] = {
        {"P001", "Gao Thom", "Bag", 150, 1, {"", "", 0, 0, {0,0,0}, {0,0,0}}},
        {"P002", "Bot Mi", "Box", 80, 1, {"", "", 0, 0, {0,0,0}, {0,0,0}}},
        {"P003", "Duong Kinh", "Kg", 200, 1, {"", "", 0, 0, {0,0,0}, {0,0,0}}},
        {"P004", "Muoi Bien", "Kg", 300, 1, {"", "", 0, 0, {0,0,0}, {0,0,0}}},
        {"P005", "Dau An", "Litre", 75, 1, {"", "", 0, 0, {0,0,0}, {0,0,0}}},
        {"P006", "Ca Hop", "Can", 40, 1, {"", "", 0, 0, {0,0,0}, {0,0,0}}}, 
        {"P007", "Mi Tom", "Pack", 500, 1, {"", "", 0, 0, {0,0,0}, {0,0,0}}},
        {"P008", "Banh Quy", "Box", 120, 1, {"", "", 0, 0, {0,0,0}, {0,0,0}}},
        {"P009", "Sua Tuoi", "Carton", 90, 1, {"", "", 0, 0, {0,0,0}, {0,0,0}}},
        {"P010", "Nuoc Sot", "Bottle", 60, 1, {"", "", 0, 0, {0,0,0}, {0,0,0}}}
    };

    int numInitialProducts = 10;
    for (int i = 0; i < numInitialProducts; i++) {
        pro[i] = initialProducts[i];
    }
    size = numInitialProducts; 
}
int isDup(Product *pro, const char id[]){  
	for (int i=0;i<size;i++){
        if (strcmp(pro[i].productId,id)==0){
            return 1;
        }
    }
    return 0;
}
void enter(Product *pro, int index){
	int isValid;
    do {
        isValid = 1;
        printf("Product ID: ");
        fgets(pro[index].productId, sizeof(pro[index].productId), stdin);
        pro[index].productId[strcspn(pro[index].productId, "\n")] = '\0';

        if (strlen(pro[index].productId) == 0) {
            printf("Id should not be blank or only space\n");
            isValid = 0;
        } 
        else if (isDup(pro, pro[index].productId)) { 
            printf("Id can not be looped for one more time\n");
            isValid = 0;
        }
    } while (!isValid);
    do {
        printf("Name: ");
        fgets(pro[index].name, sizeof(pro[index].name), stdin);
        pro[index].name[strcspn(pro[index].name, "\n")] = 0;
        if (strlen(pro[index].name) == 0) {
            printf("Name information should not be blank or contains only space\n");
        }
    } while (strlen(pro[index].name) == 0);
    do {
        printf("Unit: ");
        fgets(pro[index].unit, sizeof(pro[index].unit), stdin);
        pro[index].unit[strcspn(pro[index].unit, "\n")] = 0;
        if (strlen(pro[index].unit) == 0) {
            printf("You can not leave unit description empty or only space\n");
        }
    } while (strlen(pro[index].unit) == 0);
    do{
				printf("Quantity: ");
				if(scanf("%d",&pro[index].quantity)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
    pro[index].status = 1; 
    size++;
}
void addProduct(Product *pro) {
        clearInputBuffer();
        enter(pro, size);
}
void upd(Product *pro){
	 clearInputBuffer();
	char position[10];
	do{
        printf("Enter id of the product that you want to update description: "); 
        fgets(position,sizeof(position),stdin);
        position[strcspn(position,"\n")]=0;
        if(strlen(position)==0){
		printf("Id should not be blank or space");
	}else{
		break;
	}
}while(1);
	for(int i = 0;i<size;i++){
		if(strcmp(pro[i].productId,position)==0){
			 do {
        printf("Name: ");
        fgets(pro[i].name, sizeof(pro[i].name), stdin);
        pro[i].name[strcspn(pro[i].name, "\n")] = 0;
        if (strlen(pro[i].name) == 0) {
            printf("Name information should not be blank or contains only space\n");
        }
    } while (strlen(pro[i].name) == 0);
			pro[i].name[strcspn(pro[i].name,"\n")]=0;
		do {
        printf("Unit: ");
        fgets(pro[i].unit, sizeof(pro[i].unit), stdin);
        pro[i].unit[strcspn(pro[i].unit, "\n")] = 0;
        if (strlen(pro[i].unit) == 0) {
            printf("You can not leave unit description empty or only space\n");
        }
    } while (strlen(pro[i].unit) == 0);
			 do{
				printf("Quantity: ");
				if(scanf("%d",&pro[i].quantity)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
			break;
		}
	}
}
void showup(Product *pro, int *n){
	int pick;
	int perPage = 2;
	int current = 1;
	int totalProducts = *n; 
	int totalPages = 1;
    if (totalProducts > 0) {
        totalPages = (int)ceil((double)totalProducts / perPage);
    }
    	do{
	int start = (current  - 1)*perPage;
	int end = start +perPage;
	if (end > totalProducts) {
            end = totalProducts;
        }
		printf("\n||======================================================Library================================================||\n");
		printf("||=============================================================================================================||\n");
	for(int i =start;i<end;i++){
		printf("|| 	ID: %s|Name: %s|Quantity: %d|Unit: %s|Status: ",pro[i].productId,pro[i].name,pro[i].quantity,pro[i].unit);
		if(pro[i].status==1){
			printf("	Usable  				||");
			printf("\n");
		}else{
			printf("	Locked  				||");
			printf("\n");
		}
	}
		printf("||=============================================================================================================||\n");
		printf("||  Current page: %d				Total pages:	     	           %d     		       ||\n",current,totalPages);
		printf("||=============================================================================================================||\n");
		printf("||	1.Previous   	|	2.Next  	|	3.Custom   	|	4.Exit       		       ||\n");
		printf("||=============================================================================================================||\n");
				printf("Pick one: ");
				if(scanf("%d",&pick)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
				}else{
					clearInputBuffer();
			}
		switch (pick) {
			case 1:
				if (current >1) {
					current--;
					} else {
					printf("You are already on the first page.\n");
				}
				break;
			case 2:
				if (current < totalPages) {
					current++;
					} else {
					printf("You are already on the last page.\n");
				}
				break;
			case 3:
				do{
				printf("Product per page: ");
				if(scanf("%d",&perPage)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
				}else{
					totalPages = (int)ceil((double)totalProducts / perPage);
					clearInputBuffer();
				break;
			}
		}while(1);
				break;
			case 4: 
				printf("See ya\n");
				break;
		}
	}while(pick!=4);
}
void manage(Product *pro, int *n){
	clearInputBuffer();
	char position[10];
do{
        printf("Enter id of the product that you want to update description: "); 
        fgets(position,sizeof(position),stdin);
        position[strcspn(position,"\n")]=0;
        if(strlen(position)==0){
		printf("Id should not be blank or space");
	}else{
		break;
	}
}while(1);
	for(int i =0;i<*n;i++){
		if(strcmp(pro[i].productId,position)==0){
					do{
				printf("\n===================================\n");
				printf("||=============0.Lock============||\n");
				printf("||===========1.Activate==========||\n");
				printf("===================================\n");
				printf("Status(0 for lock,1 for usable items): ");
			scanf("%d",&pro[i].status);
			if(pro[i].status==1){
				printf("Product is activated");
				clearInputBuffer();
				break; 
			}else if(pro[i].status==0){
				printf("Product is locked");
				clearInputBuffer();
				break; 
			}else{
				printf("Please only enter 0 or 1 for status!");
				clearInputBuffer();
			}	 
		}while(1);
	}
}
}
void searchId(Product *pro,int *n){
	char find[50];
	int found = 0; 
	do{
	printf("Enter id of the product which you want to find its description: ");
	fgets(find,sizeof(find),stdin);
	find[strcspn(find,"\n")]=0;
		clearInputBuffer();
	if(strlen(find)==0){
		printf("Id should not be blank or space");
	}else{
		break;
	}
}while(1);
	for(int i =0;i<*n;i++){
		if(strcmp(pro[i].productId,find)==0){
				printf("ID: %s|Name: %s|Quantity: %d|Unit: %s|Status: ",pro[i].productId,pro[i].name,pro[i].quantity,pro[i].unit);
				
		if(pro[i].status==1){
			printf("Usable");
			printf("\n");
			
		}else{
			printf("Locked");
			printf("\n");
		}
		found = 1;
				break;
		}
	}
	if(!found){
		printf("Not found");
	}
}
void searchName(Product *pro,int *n){
	clearInputBuffer();
	char find[50];
	printf("Enter the name you want to find description: ");
	fgets(find,sizeof(find),stdin);
	find[strcspn(find,"\n")]=0;
	for(int i =0;i<*n;i++){
		if(strstr(pro[i].name,find)){
					printf("ID: %s|Name: %s|Quantity: %d|Unit: %s|Status: ",pro[i].productId,pro[i].name,pro[i].quantity,pro[i].unit);
		if(pro[i].status==1){
			printf("Usable");
			printf("\n");
		}else{
			printf("Locked");
			printf("\n");
		}
		}
	}
}
void ascendAZ(Product *pro,int *n){
	Product temp;
	for(int i=0;i<*n-1;i++){
		for (int j = 0;j<*n-1-i;j++){
			if(strcmp(pro[j].name,pro[j+1].name)>0){
				temp = pro[j];
				pro[j]=pro[j+1];
				pro[j+1]=temp;
			}
		}
	}
	for(int i =0;i<*n;i++){
		printf("|| 	ID: %s|Name: %s|Quantity: %d|Unit: %s|Status: ",pro[i].productId,pro[i].name,pro[i].quantity,pro[i].unit);
		if(pro[i].status==1){
			printf("	Usable  	||");
			printf("\n");
		}else{
			printf("	Locked  	||");
			printf("\n");
		}
	}
}
void ascendQuantity(Product *pro,int *n){
	Product tmp;
	for(int i=0;i<*n-1;i++){
		for (int j = 0;j<*n-1-i;j++){
			if(pro[j].quantity>pro[j+1].quantity){
				tmp = pro[j];
				pro[j]=pro[j+1];
				pro[j+1]=tmp;
			}
		}
	}
	for(int i =0;i<*n;i++){
		printf("|| 	ID: %s|Name: %s|Quantity: %d|Unit: %s|Status: ",pro[i].productId,pro[i].name,pro[i].quantity,pro[i].unit);
		if(pro[i].status==1){
			printf("	Usable  	||");
			printf("\n");
		}else{
			printf("	Locked  	||");
			printf("\n");
		}
	}
}
void impo(Product *pro,int *n){
		char find[50];
		int found =0;
	do{
	printf("Enter id of the product which you want to import: ");
	fgets(find,sizeof(find),stdin);
	find[strcspn(find,"\n")]=0;
		clearInputBuffer();
	if(strlen(find)==0){
		printf("Id should not be blank or space");
	}else{
		break;
	}
}while(1);
		for(int i =0;i<*n;i++){
			if(strcmp(pro[i].productId,find)==0){
				found = 1;
			if(pro[i].status==1){
			do{
			printf("Put in the amount of products that you want to import: ");
			if(scanf("%d",&pro[i].trans.imp)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
			}else if(pro[i].trans.imp<=0){
				printf("The amount should be bigger than 0!");
					clearInputBuffer();
				}else{
					pro[i].quantity+=pro[i].trans.imp;
					strcpy(pro[i].trans.transIdImp,pro[i].productId);
					clearInputBuffer();
				break;
			}
		}while(1);
	do{
			printf("Day of import: ");
			if(scanf("%d",&pro[i].trans.doti.dayImp)!=1){
					printf("Please only use integer number for this list !\n");
					clearInputBuffer();
			}else if(pro[i].trans.doti.dayImp<=0||pro[i].trans.doti.dayImp>31){
				printf("Day must be from 1 to 31!\n");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
			do{
			printf("Month of import: ");
			if(scanf("%d",&pro[i].trans.doti.monthImp)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
			}else if(pro[i].trans.doti.monthImp<=0||pro[i].trans.doti.monthImp>31){
				printf("Month should be from 1-12!\n");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
			do{
			printf("Year of import: ");
			if(scanf("%d",&pro[i].trans.doti.yearImp)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
			}else if(pro[i].trans.doti.yearImp<=0){
				printf("Year should be bigger than 0!");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
		break;
			}else{
			printf("The product need to be activated to import new quantity");
			break;
	}
	}
	}
	if(!found){
		printf("Not found");
	} 
						transCount++;
}
void expo(Product *pro,int *n){
	char find[50];
	int found =0;
	do{
	printf("Enter id of the product which you want to export: ");
	fgets(find,sizeof(find),stdin);
	find[strcspn(find,"\n")]=0;
		clearInputBuffer();
	if(strlen(find)==0){
		printf("Id should not be blank or space");
	}else{
		break;
	}
}while(1);
	for(int i =0;i<*n;i++){
	if(strcmp(pro[i].productId,find)==0){
		found = 1;
		if(pro[i].status==1){
			do{
			printf("Put in the amount of products that you want to export: ");
			if(scanf("%d",&pro[i].trans.exp)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
			}else if(pro[i].trans.exp<=0){
				printf("The amount should be bigger than 0!");
					clearInputBuffer();
				}else{
					pro[i].quantity-=pro[i].trans.exp;
					strcpy(pro[i].trans.transIdExp,pro[i].productId);
					clearInputBuffer();
				break;
			}
		}while(1);
	do{
			printf("Day of export: ");
			if(scanf("%d",&pro[i].trans.dote.dayExp)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
			}else if(pro[i].trans.dote.dayExp<=0||pro[i].trans.dote.dayExp>=31){
				printf("Day should be from 1 to 31!\n");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
			do{
			printf("Month of export: ");
			if(scanf("%d",&pro[i].trans.dote.monthExp)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
			}else if(pro[i].trans.dote.monthExp<=0||pro[i].trans.dote.monthExp>12){
				printf("Month should be from 1 to 12!\n");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
			do{
			printf("Year of export: ");
			if(scanf("%d",&pro[i].trans.dote.yearExp)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
			}else if(pro[i].trans.dote.yearExp<=0){
				printf("Year should be bigger than 0!");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
			break;
		}else{
			printf("The product need to be activated to export new quantity");
			break;
	}
	}
	}
		if(!found){	
			printf("Not found");
	} 
						transCount++;
}
void hisImpo(Product *pro,int *n){
	if(transCount==0){
		printf("There is no transaction recently\n");
	}else if(transCount>0){
	printf("\n||======================================================History of importation================================================||\n");
		printf("||===========================================================================================================================||\n");
	for(int i =0;i<*n;i++){
				printf("ID: %s|Name: %s|Quantity: %d|Unit: %s|Id of transaction: %s|Date of import: %d/%d/%d|Status: ",pro[i].productId,pro[i].name,pro[i].quantity,pro[i].unit,pro[i].trans.transIdImp,pro[i].trans.doti.dayImp,pro[i].trans.doti.monthImp,pro[i].trans.doti.yearImp);
		if(pro[i].status==1){
			printf("Usable");
			printf("\n");
			
		}else{
			printf("Locked");
			printf("\n");
		}
		}
		printf("||==========================================================================================================================||\n");
	}
	}
void hisExpo(Product *pro,int *n){
	if(transCount==0){
		printf("There is no transaction recently\n");
	}else if(transCount>0){
	printf("\n||======================================================History of exportation================================================||\n");
		printf("||===========================================================================================================================||\n");
	for(int i =0;i<*n;i++){
				printf("ID: %s|Name: %s|Quantity: %d|Unit: %s|Id of transaction: %s|Date of export: %d/%d/%d|Status: ",pro[i].productId,pro[i].name,pro[i].quantity,pro[i].unit,pro[i].trans.transIdExp,pro[i].trans.dote.dayExp,pro[i].trans.dote.monthExp,pro[i].trans.dote.yearExp);
				
		if(pro[i].status==1){
			printf("Usable");
			printf("\n");
			
		}else{
			printf("Locked");
			printf("\n");
		}
		printf("||=============================================================================================================================||\n");
	}
}
}
int main(){
	Product pro[100] ;
	int n,i,decision; 
	int choice,selection,pick,get,take,set,grab;
	initializeProducts(pro);
do{
		mainMenu();
		do{
		printf("Your decision: ");
		if(scanf("%d",&decision)!=1){
			printf("Please only put in integer number!\n");
			clearInputBuffer();   
		}else if(decision<=0||decision>3){
			printf("Please only enter number in the range from 1 to 3!\n");
		}else{
			clearInputBuffer();
			break;
		}
		}while(1);
		switch(decision){
			case 1:
				do{
				assiMenu();
				do{
				printf("Pick one: ");
				if(scanf("%d",&pick)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
				}else if(pick<=0||pick>7){
					printf("Please only enter number in the range from 1 to 7!\n");
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
				switch(pick){
				
					case 1:
						addProduct(pro);
						break;
					case 2:
						upd(pro);
						break;
					case 3:
						manage(pro,&size);
						break;
					case 4:
						do{
						printf("\n==============================\n");
						printf("||=======1.Search by Id=======||\n");
						printf("||======2.Search by Name======||\n");
						printf("||===========3.Back===========||\n");
						printf("==============================\n");
						do{
						printf("Your selection: ");
						if(scanf("%d",&selection)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
					}else if(selection<=0||selection>3){
					printf("Please only enter number in the range from 1 to 3!\n");
						}else{
					clearInputBuffer();
						break;
						}
					}while(1);
						switch(selection){
							case 1:
								searchId(pro,&size);
								break;
							case 2:
								searchName(pro,&size);
								break;
							case 3:
								break;
						}
						}while(selection!=3);
						break;
					case 5:
						showup(pro,&size);
						break;
					case 6:
						do{
						printf("==============Arrange menu==========\n");
						printf("||==1. Arrange bases on alphabet==||\n");
						printf("||====2.Arrange base on amount====||\n");
						printf("||==============3.Back============||\n");
						printf("====================================\n");
						do{
						printf("Your choice: ");
						if(scanf("%d",&choice)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
					}else if(choice<=0||choice>3){
					printf("Please only enter number in the range from 1 to 3!\n");
						}else{
					clearInputBuffer();
						break;
						}
					}while(1);
						switch(choice){
							case 1:
								ascendAZ(pro,&size);
								break;
							case 2:
								ascendQuantity(pro,&size);
								break;
							case 3:
								break;
					}
					}while(choice!=3);
						break;
					case 7:
					break;
					}
					}while(pick!=7);
				break;
			case 2:
				do{
		subMenu();
		do{
		printf("Grab one: ");
		if(scanf("%d",&grab)!=1){
		printf("This menu only assits integer choices please choose it correctly!\n");	
		clearInputBuffer();
	}else if(grab<=0||grab>3){
		printf("Please only enter number in the range from 1 to 3!\n");
	}else{
		clearInputBuffer();
		break;
	}
}while(1);
		switch(grab){
			case 1:
				do{
						printf("\n==========================\n");
						printf("||=======1.Import=======||\n");
						printf("||=======2.Export=======||\n");
						printf("||========3.Back========||\n");
						printf("==========================\n");
						do{
						printf("Your selection: ");
						if(scanf("%d",&take)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
					}else if(take<=0||take>3){
					printf("Please only enter number in the range from 1 to 2!\n");
						}else{
					clearInputBuffer();
						break;
						}
					}while(1);
					switch(take){
						case 1:
							impo(pro,&size);
							break;
						case 2:
							expo(pro,&size);
							break;
						case 3:
							break;
						}
					}while(take!=3);
				break;
			case 2:
				do{
						printf("\n==================================\n");
						printf("||=======1.Import history=======||\n");
						printf("||=======2.Export history=======||\n");
						printf("||============3.Back============||\n");
						printf("==================================\n");
						do{
						printf("Your selection: ");
						if(scanf("%d",&set)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
					}else if(set<=0||set>3){
					printf("Please only enter number in the range from 1 to 3!\n");
						}else{
					clearInputBuffer();
						break;
						}
					}while(1);
					switch(set){
						case 1:
						hisImpo(pro,&size);
						break;
					case 2:
						hisExpo(pro,&size);
						break;
					case 3:
						break;
					}
					}while(set!=3);
				break;
			case 3:
				break;
		}
	}while(grab!=3);
				break;
			case 3:
				printf("Thanks for using!");
				exit(0);
				break;
			}
	}while(1);
}

