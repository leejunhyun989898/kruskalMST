#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

typedef struct {
    int u, v, w;
} edge;

edge edges[MAX_EDGES]; //���� �迭
int parent[MAX_VERTICES]; //������ ���� �θ� ��� ���� �迭
int n = 6, m = 10; //n = ������ ���� , m = ������ ����

//��尡 �ش�Ǵ� ������ ã�� �Լ�
int find(int x) {
    
    if (parent[x] == x) {
        return x; //���� ���տ� ���Ұ�� x�� ��ȯ
    }
    return find(parent[x]); //���տ� ������ ������ ��� ã��
}

//�ΰ��� ������ �ϳ��� ��ġ�� �Լ�
void union_(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}

//�� ���Ҹ� ���Ͽ� ���� ���� ���� �Լ�
int compare(const void* a, const void* b) {
    edge* ea = (edge*)a;
    edge* eb = (edge*)b;
    return ea->w - eb->w;
}

//���� ����
void bubble_sort() {
    int i, j;
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < m; i++) {
        printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
    }
}

//kruskal �˰���
int kruskal() {
    int i, j;
    int min_cost = 0;
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    // edges �迭�� ��� ���� ���
    printf("Sorted edges:\n");
    bubble_sort();


    // MST ���� ���
    printf("Kruskal MST:\n");
    for (i = 0, j = 0; i < m && j < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            union_(u, v);
            printf("%d - %d : %d\n", u, v, edges[i].w);
            min_cost += edges[i].w;
            j++;
        }
    }
    return min_cost;
}
int main() {
	int i;

	edges[0].u = 0; edges[0].v = 1; edges[0].w = 8;
	edges[1].u = 0; edges[1].v = 3; edges[1].w = 2;
	edges[2].u = 0; edges[2].v = 4; edges[2].w = 4;
	edges[3].u = 1; edges[3].v = 2; edges[3].w = 1;
	edges[4].u = 1; edges[4].v = 3; edges[4].w = 4;
	edges[5].u = 1; edges[5].v = 5; edges[5].w = 2;
	edges[6].u = 2; edges[6].v = 5; edges[6].w = 1;
	edges[7].u = 3; edges[7].v = 4; edges[7].w = 3;
	edges[8].u = 3; edges[8].v = 5; edges[8].w = 7;
	edges[9].u = 4; edges[9].v = 5; edges[9].w = 9;
	printf("Kruskal MST�� ����ġ �� : %d\n", kruskal());
	return 0;
}