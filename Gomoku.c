#include<stdio.h>
#define elements 7

//list[x][y]
void init_adlist(int list[elements][elements]){
	
	int i = 0;
	int j = 0;
	
	//set all zero
	for(i = 0; i<elements; i++){
		for(j = 0; j<elements; j++){
			list[i][j] = 0;
		}	
	}
	
	//set 1's
	list[1][3] = 1;
	list[1][4] = 1;
	list[2][3] = 1;
	list[3][2] = 1;
	list[3][3] = 1;
	list[4][3] = 1;
	list[5][3] = 1;
	
} // end of init_adlist

void show_elements(int list[elements][elements]){
	
	int i = 0;
	int j = 0;

	for(j = elements-1; j >=0; j--){
		for(i = 0; i<elements; i++){
			printf("%d\t",list[i][j]);
		}
		printf("\n");
	}
} // end of show_elements

void four_case_up(int icase, int *x, int *y){
	switch (icase) {
        case 1:
            *y = (*y) + 1;
            break;
             
        case 2:
            *x = (*x) + 1;
			*y = (*y) + 1;
            break;
		
		case 3:
			*x = (*x) + 1;
			break;
			
		case 4:
            *x = (*x) + 1;
			*y = (*y) - 1;
            break;		
	}
}

void four_case_down(int icase, int *x, int *y){
	switch (icase) {
        case 1:
            *y = (*y) - 1;
            break;
             
        case 2:
            *x = (*x) - 1;
			*y = (*y) - 1;
            break;
		
		case 3:
			*x = (*x) - 1;
			break;
			
		case 4:
            *x = (*x) - 1;
			*y = (*y) + 1;
            break;	
	}		
}

int is_one(int x, int y, int list_sample[elements][elements]){
	
	int flag = 0;
	
	if ( ( x < 0) | (x >= elements) )
		flag = 0;
	else if ( ( y < 0) | (y >= elements) )
		flag = 0;
	else if(list_sample[x][y] == 0){
		flag = 0;
	} else {
		flag = 1;
	}
	
	return flag;
}

int main(void){

	char ch;
	int list_sample[elements][elements] = {0};
	int x = 3, y = 3;
	int i = 1;
	int flag = 1;
	int counter = 1;
	
	init_adlist(list_sample);
	show_elements(list_sample);
	
	for(i = 1; i < 5; i++){
		
		x = 3; y = 3; flag = 1;
		
		while(flag == 1){
			four_case_up(i, &x, &y);
			if(is_one(x,y,list_sample) == 1){
				counter++;
				flag = 1;
			} else {
				flag = 0;
				break;
			}		
		}//end of while

		x = 3; y = 3; flag = 1;
		
		while(flag == 1){
			four_case_down(i, &x, &y);
			if(is_one(x,y,list_sample) == 1){
				counter++;
				flag = 1;
			} else {
				flag = 0;
				break;
			}		
		}//end of while	
		
		if(counter == 5)
			printf("win in case %d!\n",i);
		
		counter = 1;
	}
	
	ch = getchar();
}
