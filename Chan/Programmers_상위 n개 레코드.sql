-- 플랫폼: 프로그래머스
-- 문제: 상위 n개 레코드 - Lv. 1
-- 링크: https://school.programmers.co.kr/learn/courses/30/lessons/59405
-- 언어: MySQL

SELECT    A.NAME
FROM      ANIMAL_INS A
ORDER BY  A.DATETIME ASC
LIMIT     1