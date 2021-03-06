# 알고리즘 성능 평가

### 복잡도

* **알고리즘 성능**을 나타내는 척도

* 시간복잡도
  * 특정한 크기의 입력에 대하여 **알고리즘 수행 시간** 분석
* 공간복잡도
  * 특정한 크기의 입력에 대하여 **알고리즘 메모리 사용량** 분석
* 복잡도가 낮을수록 좋은 알고리즘



### 빅오 표기법(Big-O Notation)

* **가장 빠르게 증가하는 항**만 고려하는 표기법

* 함수의 상한값

* | 순위             | 명칭           |
  | ---------------- | -------------- |
  | O(1)             | 상수 시간      |
  | O(logN)          | 로그 시간      |
  | O(N)             | 선형 시간      |
  | O(NlogN)         | 로그 선형 시간 |
  | O(N<sup>2</sup>) | 이차 시간      |
  | O(N<sup>3</sup>) | 삼차 시간      |
  | O(2<sup>n</sup>) | 지수 시간      |


----------------------------------------------
# 알고리즘 설계 Tip

* 연산 횟수가 5억을 넘어가는 경우, 소요 시간

  * C언어 기준 1~3초
  * Python 기준 5~15초

* 코딩 테스트 문제에서 시간 제한 통상 **1~5초**

* 문제에서 가장 먼저 시간 제한(수행시간 요구사항) 확인

  * Python 기준, 시간 제한 1초

    | N의 범위   | 시간복잡도       |
    | ---------- | ---------------- |
    | 500        | O(N<sup>3</sup>) |
    | 2,000      | O(N<sup>2</sup>) |
    | 100,000    | O(NlogN)         |
    | 10,000,000 | O(N)             |





