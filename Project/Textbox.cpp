#include"Textbox.h"

void setnotseleted(TextBox**& Studenttextbox, int n, int x, int y) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 6; j++)
            if (i != x || j != y)
                Studenttextbox[i][j].setselected(false);
}