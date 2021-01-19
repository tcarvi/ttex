#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_STRING 4
#define MAX_STRING_SIZE 40

FILE *stream0, *stream1, *stream2;

int printInicialComment(void){
    fputc('<', stream2);
    fputc('!', stream2);
    fputc('-', stream2);
    fputc('-', stream2);
    fputc(' ', stream2);
    fputc('t', stream2);
    fputc('T', stream2);
    fputc('a', stream2);
    fputc('g', stream2);
    fputc('#', stream2);
    return 0;
}

int printFinalComment(void){
    fputc(' ', stream2);
    fputc('-', stream2);
    fputc('-', stream2);
    fputc('>', stream2);
    fputc('\n', stream2);
    return 0;
}

void print_array(char arr[NUMBER_OF_STRING][MAX_STRING_SIZE])
{
	for (int i = 0; i < NUMBER_OF_STRING; i++)
	{
		printf("'%s' has length %llu\n", arr[i], strlen(arr[i]));
	}
}

int main(void)
{

    // 1 - Ler index.html e procurar por arquivo com mesmo id.
    // 2 - Colocar a tTag# do arquivo de estrutura no local correto de index.html

    errno_t err;

    // Open for read (will fail if file "html/body.html" doesn't exist)
    err = fopen_s( &stream0, "html/body.html", "r" );
    if( err == 0 ) {
        printf( "The file 'html/body.html' was opened\n" );
    } else {
        printf( "The file 'html/body.html' was not opened\n" );
    }



    // Open for read (will fail if file "html/footerSection.html" doesn't exist)
    err  = fopen_s( &stream1, "html/footerSection.html", "r" );
    if( err == 0 ) {
        printf( "The file 'html/footerSection.html' was opened\n" );
    } else {
        printf( "The file 'html/footerSection.html' was not opened\n" );
    }

    // Open for write
    err = fopen_s( &stream2, "build/index.html", "w+" );
    if( err == 0 ) {
        printf( "The file 'build/index.html' was opened\n" );
    } else {
        printf( "The file 'build/index.html' was not opened\n" );
    }

    // procurar id=" até "
    int i1 = fgetc(stream1); // for t
    int i2 = fgetc(stream1); // for T
    int i3 = fgetc(stream1); // for a
    char tempI;
    bool podeAcrescentarId = false;
    bool podeJuntarNaId = false;
    char ids[NUMBER_OF_STRING][MAX_STRING_SIZE];
    int numberOfId = 0;
    char id[MAX_STRING_SIZE];
    while ( (tempI=fgetc(stream0)) != EOF ) {
        printf("tempI = %c\n", tempI);
        if (podeAcrescentarId == false){
            // Não executo o comando putchar(temp);
            if(tempI == '"' && i1 == 'i' && i2 == 'd' && i3 == '='){
                podeJuntarNaId = true;
                i1 = i2;
                i2 = i3;
                i3 = tempI;
                printf("podeJuntarNaId now = true.\n");
                continue;
            }
        }
        if(podeJuntarNaId){
            strcat(id,&tempI);
            if(tempI == '"'){
                podeJuntarNaId = false;
                podeAcrescentarId = true;
                i1 = i2;
                i2 = i3;
                i3 = tempI;
                printf("podeAcrescentarId now = true.\n");
                continue;
            }
        }
        if(podeAcrescentarId){
            strcpy(ids[numberOfId], id);
            numberOfId++;
            memset(id, 0, sizeof id);
            podeJuntarNaId = false;
            podeAcrescentarId = false;
            printf("podeJuntarNaId e podeAcrescentarId now = false.\n");
        }
        // Swap de atualização do loop
        i1 = i2;
        i2 = i3;
        i3 = tempI;
    }

	printf("Before process:\n");
	print_array(ids);

	// for (int i = 0; i < NUMBER_OF_STRING; i++)
	// {
	// 	for (int j = 0, k = strlen(ids[i]) - 1; j < k; j++, k--)
	// 	{
	// 		char tempChar = ids[i][j];
	// 		ids[i][j] = ids[i][k];
	// 		ids[i][k] = tempChar;
	// 	}
	// }

	// printf("\nAfter reverse:\n");
	// print_array(ids);






    // Begin: <!-- tTag# -->
    // End:   <!-- tTag# -->
    int c1 = fgetc(stream1); // for t
    int c2 = fgetc(stream1); // for T
    int c3 = fgetc(stream1); // for a
    int c4 = fgetc(stream1); // for g
    int temp;
    bool podeCopiar = false;

    while ( (temp=fgetc(stream1)) != EOF ) {
        if (podeCopiar == false){
            // Não executo o comando putchar(temp);
            if(temp == '#' && c1 == 't' && c2 == 'T' && c3 == 'a' && c4 == 'g'){
                podeCopiar = true;
                printInicialComment();
                c1 = c2;
                c2 = c3;
                c3 = c4;
                c4 = temp;
                printf("podeCopiar now = true.\n");
                continue;
            }

        }
        if(podeCopiar){
            fputc(temp, stream2);
            if(temp == '#' && c1 == 't' && c2 == 'T' && c3 == 'a' && c4 == 'g'){
                podeCopiar = false;
                printFinalComment();
                c1 = c2;
                c2 = c3;
                c3 = c4;
                c4 = temp;
                printf("podeCopiar now = false.\n");
                continue;
            }
        }

        // Swap de atualização do loop
        c1 = c2;
        c2 = c3;
        c3 = c4;
        c4 = temp;
    }

    // Close input stream if it isn't NULL
    if( stream0 ) {
        err = fclose( stream0 );
        if ( err == 0 ) {
            printf( "The file 'html/body.html' was closed\n" );
        } else {
            printf( "The file 'html/body.html' was not closed\n" );
        }
   }

        // Close input stream if it isn't NULL
    if( stream1 ) {
        err = fclose( stream1 );
        if ( err == 0 ) {
            printf( "The file 'html/footerSection.html' was closed\n" );
        } else {
            printf( "The file 'html/footerSection.html' was not closed\n" );
        }
   }

           // Close output stream if it isn't NULL
    if( stream2 ) {
        err = fclose( stream2 );
        if ( err == 0 ) {
            printf( "The file 'build/index.html' was closed\n" );
        } else {
            printf( "The file 'build/index.html' was not closed\n" );
        }
   }

    // All other files are closed:
    int numclosed = _fcloseall( );
    printf( "Number of files closed by _fcloseall: %u\n", numclosed );

    return 0;
}












	

