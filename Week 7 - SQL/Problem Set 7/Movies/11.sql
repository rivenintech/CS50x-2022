SELECT title
  FROM movies
  JOIN ratings
    ON movies.id=ratings.movie_id
 WHERE movie_id IN
       (SELECT movie_id
          FROM stars
         WHERE person_id=
               (SELECT id
                  FROM people
                 WHERE name='Chadwick Boseman'))
 ORDER BY rating DESC, title ASC
 LIMIT 5;