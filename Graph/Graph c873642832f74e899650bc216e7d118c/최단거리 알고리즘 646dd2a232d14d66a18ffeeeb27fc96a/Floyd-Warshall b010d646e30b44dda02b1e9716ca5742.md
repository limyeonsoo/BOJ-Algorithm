# Floyd-Warshall

## Floyd-Warshall

전체 쌍 최단 경로 풀이 가능.

DP적 관점.

> 전제 조건

- 순환이 없다면 음의 가중치도 가능.
- 어떤 두 정점 사이의 최단 경로는
**경유지 (K)를 거치거나**/**거치지않거나** 둘 중 하나.
→ **A-B** / **A-K-B**
- A-K-B가 최단 경로라면
A-K와 K-B도 최단경로다.

> 시간 복잡도

- 모든 노드들의 조합에 대해서 현재까지의 최단 경로
총 |V|-1 번 반복 ⇒ $O(|V|^3)$

> 특징

- 모든 경유지에 대해서 모든 정점→ 모든 정점을 확인하므로 연산회수는 $V^3$ ⇒ $O(V^3)$

> 단계

1. D[i][j] : i → j 까지의 최단 거리 저장 배열. 초기화 0 or INF
2. D[i][j]의 간선 정보 저장 E = (I,J,W) ⇒ D[i][j] = W
3. **경유지 K ( 1≤ K ≤ V)**

       **출발 정점 i (1≤ i ≤ V)**

           **도착 정점 j (1 ≤ j ≤ V)**

    **⇒ D[i][j] = min(D[i][j], D[i][k] + D[k][j])**