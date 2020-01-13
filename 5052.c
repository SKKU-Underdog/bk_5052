#include <stdio.h>
#include <stdlib.h>

typedef struct Trie{
	struct Trie* next[10];
	int end;
}trie;

int slen(char* str){
	int result=0;
	while(1){
		if(str[result]<='9'&&str[result]>='0')
			result++;
		else
			return result;
	}
}

int main(){
	int T,n,num,fin;
	char str[11];
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&n);
		trie* head=(trie*)malloc(sizeof(trie));
		trie* current=NULL;
		head->end=0;
		fin=0;
		for(int i=0;i<10;i++) head->next[i]=NULL;
		for(int i=0;i<n;i++){
			scanf("%s",str);
			int ran=slen(str);
			current=head;
			for(int j=0;j<ran;j++){
				int digit=str[j]-'0';
				if(current->next[digit]==NULL){
					trie* temp=(trie*)malloc(sizeof(trie));
					current->next[digit]=temp;
					current=temp;
					if(j==ran-1){
						current->end=1;
					}
				}
				else{
					current=current->next[digit];
					if(current->end==1){
						fin=1;
						break;
					}
					if(j==ran-1){
						fin=1;
						break;
					}
				}
			}
		}
		if(fin==1) printf("NO\n");
		else printf("YES\n");
	}
}
