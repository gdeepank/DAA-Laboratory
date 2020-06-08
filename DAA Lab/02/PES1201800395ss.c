#include<stdio.h>
#include<string.h>

int searchFirstOccurrence(char *pattern, char *text){
    int p = strlen(pattern);
    int t = strlen(text);
    for(int i = 0; i<(t-p+1); ++i){
      int j = 0;
      while(j < p && pattern[j] == text[i+j])
         ++j;
      if(j == p)
         return i;
    }
    return -1;
}

int searchLastOccurrence(char *pattern, char *text){
	int p = strlen(pattern);
    int t = strlen(text);
    for(int i = t-p; i >= 0; i--){
      int j = 0;
      while(j < p && pattern[j] == text[i+j])
         ++j;
      if(j == p)
         return i;
    }
   return -1;
}

int numOccurrences(char *pattern, char *text){
	int p = strlen(pattern);
	int t = strlen(text);
	int count = 0;
	for(int i = 0; i < t-p; ++i){
		int j;
		for(j = 0; j < p; ++j){
			if(text[i+j] != pattern[j])
				break;	
		}
		if(j == p)
			++count;
	}
	return count;
}

int longestPrefix(char *pattern, char *text){
    int p = strlen(pattern);
    int t = strlen(text);
    int lpe = 0;
    for(int i = 0; i < (t-p+1); ++i){
 	   int j = 0;
       while(j < p && pattern[j] == text[i+j])
           j++;
       if(j > lpe)
           lpe = j;
    }
        return lpe;
}

int charactersCompared(char *pattern, char *text){      
    int count = 0;
    int p = strlen(pattern);
    int t = strlen(text);
    for(int i = 0; i < (t-p+1); ++i){
    	int j = 0;
    	while(j < p){
       		if(pattern[j] == text[i+j]){
                 ++j;
                 ++count;
            }
            else{
               count++;
               break;
            }               
        }                   
    }
    return count;
}

