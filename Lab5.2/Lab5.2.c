#include <stdio.h>

void find_combinations(int score) {
    for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
        for (int td_fg = 0; td_fg * 7 + td_2pt * 8 <= score; td_fg++) {
            for (int td = 0; td * 6 + td_fg * 7 + td_2pt * 8 <= score; td++) {
                for (int fg = 0; fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= score; fg++) {
                    int safety = score - (fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8);
                    if (safety >= 0 && safety % 2 == 0) {
                        safety /= 2;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               td_2pt, td_fg, td, fg, safety);
                    }
                }
            }
        }
    }
}

int main() {
    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        printf("Enter the NFL score: ");
        int score;
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("possible combinations of scoring plays:\n");
        find_combinations(score);
    }
    return 0;
}
