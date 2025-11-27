#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int size =0;
typedef struct Transaction{
	char transId[20];
	int imp;
	int exp;
	char date[15];
};
typedef struct Product{
	char productId[10];
	char name[50];
	char unit[10];
	int quantity;
	int status = 1;
	Transaction trans;
};
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void mainMenu(){
	printf("\n||===================Gocery store management systems==================||\n");
	printf("||                1.Products                                          ||\n");
	printf("||                2.Import and export                                 ||\n");
	printf("||                3.Exit                                              ||\n");
	printf("||====================================================================||\n");
};
void assiMenu(){
	printf("\n||=============Gocery store management systems-Product============||\n");
	printf("||                       1.Add more products                      ||\n");
	printf("||                       2.Update information                     ||\n");
	printf("||                       3.Manage status                          ||\n");
	printf("||                       4.Search                                 ||\n");
	printf("||                       5.Print out the list                     ||\n");
	printf("||                       6.Arrange list                           ||\n");
	printf("||                       7.Back                                   ||\n");
	printf("||================================================================||\n");
}
void subMenu(){
	printf("\n||=========Gocery store management systems-Import and export======||\n");
	printf("||                1.Trading of import and export                  ||\n");
	printf("||                2.History of import and export                  ||\n");
	printf("||                3.Back                                          ||\n");
	printf("||================================================================||\n");
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
    int n;
    printf("Limit: ");
    scanf("%d",&n);
    clearInputBuffer();
    if (n < 0) n = 0;
    for (int i = 0; i < n; i++) {
        enter(pro, size);
    }
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
	int p,pick;
	 do{
				printf("Product per page ");
				if(scanf("%d",&p)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
	int perPage = p;
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
		printf("\n||=============================Library==================================||\n");
		printf("||======================================================================||\n");
	for(int i =start;i<end;i++){
		printf("|| 	ID: %s|Name: %s|Quantity: %d|Unit: %s|Status: ",pro[i].productId,pro[i].name,pro[i].quantity,pro[i].unit);
		if(pro[i].status==1){
			printf("	Usable  	||");
			printf("\n");
		}else{
			printf("	Locked  	||");
			printf("\n");
		}
	}
		printf("||======================================================================||\n");
		printf("||  Current page: %d			Total pages:	     	  %d     ||\n",current,totalProducts);
		printf("||======================================================================||\n");
		printf("||	1.Previous	|	2.Next		|	3.Exit		||\n");
		printf("||======================================================================||\n");
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
				printf("Exiting product list view.\n");
				break;
		}
	}while(pick!=3);
}
void manage(Product *pro, int *n){
	fflush(stdin);
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
				printf("\n===================================\n");
				printf("||            0.Lock             ||\n");
				printf("||            1.Usable           ||\n");
				printf("===================================\n");
				printf("Status(0 for lock,1 for usable items): ");
			scanf("%d",&pro[i].status);
			break;
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
				found = 1;
				break;
		if(pro[i].status==1){
			printf("Usable");
			printf("\n");
			
		}else{
			printf("Locked");
			printf("\n");
		}
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
			if(pro[i].status==1){
			do{
			printf("Put in the amount of products that you want to import: ");
			if(scanf("%d",&pro.trans.imp)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
			}else if(pro.trans.imp<=0){
				printf("The amount should be bigger than 0!");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
		}else{
			printf("The product need to be activated to import new quantity");
	}
	for(int i =0;i<*n;i++){
	pro[i].quantity+=pro.trans.imp;
	}
}
void expo(Product *pro,int *n){
	if(pro[i].status==1){
			do{
			printf("Put in the amount of products that you want to export: ");
			if(scanf("%d",&pro.trans.exp)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
			}else if(pro.trans.exp<=0){
				printf("The amount should be bigger than 0!");
					clearInputBuffer();
				}else{
					clearInputBuffer();
				break;
			}
		}while(1);
		}else{
			printf("The product need to be activated to export new quantity");
	}
	for(int i =0;i<*n;i++){
	pro[i].quantity-=pro.trans.exp;
	}
}
void hisImpo(Product *pro,int *n){
	for(int i =0;i<*n;i++){
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
		
	}
}
int main(){
	Product pro[100] ;
	int n,i,decision;
	int choice,selection,pick,get;
do{
		mainMenu();
		do{
		printf("Your decision: ");
		if(scanf("%d",&decision)!=1){
			printf("Please only put in integer number!\n");
			clearInputBuffer();           
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
						manage(pro,&n);
						break;
					case 4:
						printf("\n==============================\n");
						printf("||=======1.Search by Id=======||\n");
						printf("||======2.Search by Name======||\n");
						printf("==============================\n");
						do{
						printf("Your selection: ");
						if(scanf("%d",&selection)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
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
						}
						break;
					case 5:
						showup(pro,&size);
						break;
					case 6:
						printf("1. Arrange bases on alphabet\n");
						printf("2.Arrange base on amount\n");
						do{
						printf("Your choice: ");
						if(scanf("%d",&choice)!=1){
					printf("Please only use integer number for this list!\n");
					clearInputBuffer();
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
						}
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
		printf("Get one: ");
		if(scanf("%d",&get)!=1){
		printf("This menu only assits integer choices please choose it correctly!\n");	
		clearInputBuffer();
	}else{
		clearInputBuffer();
		break;
	}
}while(1);
		switch(decision){
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				break;
		}
	}while(get!=3);
				break;
			case 3:
				printf("Thanks for using!");
				exit(0);
				break;
			}
	}while(1);
}
