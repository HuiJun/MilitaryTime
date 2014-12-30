#include <stdio.h>
#include <string.h>
#include <time.h>

void findTimeZone( char *offset, char *timezone );
void strToUpper( char *text );

int main( void )
{
    time_t timer;
    struct tm *tm_info;
    char day_time[24], year_month[24], buffer[80];
    char offset[6], *timezone;

    time( &timer );
    tm_info = localtime( &timer );

    strftime( day_time, 24, "%d%H%M", tm_info );

    strftime( offset, 6, "%z", tm_info );
    findTimeZone( offset, timezone );

    strftime( year_month, 24, "%b%y", tm_info );

    strcpy( buffer, day_time );
    strcat( buffer, timezone );
    strToUpper( year_month );
    strcat( buffer, year_month );

    puts( buffer );

    return 0;
}

void strToUpper( char *text )
{
    int i;
    for( i = 0; i <= strlen(text); i++ ) {
        if( ( text[i] > 96 ) && ( text[i] < 123 ) )
            text[i] = text[i] - 'a' + 'A';
    }
}

void findTimeZone( char *offset, char *timezone ) {
    int i, compare;

    const char *timezones_values[25] = {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "K", "L", "M",
        "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y",
        "Z"
    };

    const char *timezones_map[25] = {
        "+0100", "+0200", "+0300", "+0400", "+0500", "+0600", "+0700", "+0800", "+0900", "+1000", "+1100", "+1200",
        "-0100", "-0200", "-0300", "-0400", "-0500", "-0600", "-0700", "-0800", "-0900", "-1000", "-1100", "-1200",
        "+0000"
    };

    for( i = 0; i < 25; i++ ) {
        compare = strcmp( timezones_map[i], offset );
        if( !compare ) {
            timezone[0] = *timezones_values[i];
            timezone[1] = '\0';
        }
    }
}
