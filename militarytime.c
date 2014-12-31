#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "militarytime.h"

int main( int argc, char *argv[] )
{
    int          i, c;
    char        *timezone_request;
    extern char *optarg;
    extern int   optind, optopt;
    time_t       timer;
    struct tm   *tm_info;

    time( &timer );

    if ( argc > 1 ) {
        for ( i = 1; i < argc; i++ ) {
            while ( ( c = getopt(argc, argv, ":l:" ) ) != -1 ) {
                switch( c ) {
                case '?':
                    fprintf(stderr, "Unrecognized option: -%c\n", optopt);
                    return 0;
                default:
                    tm_info = localtime( &timer );
                    break;
                }
            }
        }
    } else {
        tm_info = gmtime( &timer );
    }

    makeTime( tm_info );

    return 0;
}

void makeTime( struct tm *tm_info )
{
    char day_time[24], year_month[24], buffer[80];
    char offset[6], *timezone;

    strftime( day_time, 24, "%d%H%M", tm_info );

    strftime( offset, 6, "%z", tm_info );
    findTimeZone( offset, timezone );

    strftime( year_month, 24, "%b%y", tm_info );
    strToUpper( year_month );

    strcpy( buffer, day_time );
    strcat( buffer, timezone );
    strcat( buffer, year_month );

    puts( buffer );
}

void strToUpper( char *text )
{
    int i;
    for( i = 0; i <= strlen(text); i++ ) {
        if( ( text[i] > 96 ) && ( text[i] < 123 ) )
            text[i] = text[i] - 'a' + 'A';
    }
}

void findTimeZone( char *offset, char *timezone )
{
    int i;
    for( i = 0; i < 25; i++ ) {
        if( !strcmp( timezones_map[i], offset ) ) {
            timezone[0] = *timezones_values[i];
            timezone[1] = '\0';
        }
    }
}
