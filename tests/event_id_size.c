#include <stdio.h>
#include "../include/bre/event_id.h"


int main() {
    printf("%zu\n", sizeof(EventId));
    printf("bytes: %zu bytes\n", sizeof(((EventId * )0 ) -> bytes));
    return 0;
}