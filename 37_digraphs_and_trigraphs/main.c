??=include <stdio.h>
??=include <stdlib.h>

// compiler flag -trigraphs and -digraphs
// bunch of characters that can be used

int main(void)
<%
    int xs??(??) = {1, 2, 3};
    for (int i = 0; i < 3; i++)
        printf("xs[i] = %d\n", xs[i]);
    printf("%d\n", 1 ? 42 : 777);
    return 0;
%>
