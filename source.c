#include<stdio.h>
#include<stdlib.h>

typedef struct _NUM_DIC{

	char num;
	struct _NUM_DIC *next[10];

}NUM_DIC

NUM_DIC* _init(int num){
	NUM_DIC* tmp;

	tmp = (NUM_DIC*)malloc(sizeof(NUM_DIC));
	tmp->num = num;

	return tmp;
}

int strlen(char number[]){
	int cnt=0;

	while(number[cnt] != '\0'){
		cnt++;
	}

	return cnt;
}

int searchNum(NUM_DIC *head ,char number[]){
	
	int num,flag;

	for(int i=0;i<strlen(number);i++){
		num = number[i]-'0';
		if(head->next[num] == NULL){
			flag = 0;
			for(int j=0;j<10;j++){
				if( head->next[j] != NULL){
					flag = 1;
					break;
				}
			}
			if(!flag)
				return 1;
			head->next[num] = _init(num);
		}
		head = head->next[num];
	}

	return 0;
}

int main()
{
	int t,n;
	char number[10001];
	int flag;
	NUM_DIC *head;

	scanf("%d",&t);

	for(int i=0;i<t;i++){
		scanf("%d\n",&n);
		flag = 0;
		head = _init(0);
		for(int j=0;j<n;j++){
			scanf("%s",number);
			if(flag)
				continue;
			if(searchNum(number)){
				flag = 1;
			}
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
}
