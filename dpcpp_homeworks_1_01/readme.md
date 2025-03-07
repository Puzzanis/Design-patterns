﻿### Задание 1

Реализуйте класс `SqlSelectQueryBuilder`, который можно использовать для построения
простых SELECT-запросов.

Пример использования класса:
```
#inclide "sql_query_builder.h"

int main {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    
    static_assert(query_builder.BuildQuery(), 
                    "SELECT name, phone FROM students WHERE id=42 AND name=John;");
}
```
#### Обратите внимание на следующие моменты
1. Методы построения запроса `AddColumn, AddFrom, AddWhere` могут вызывать в любом порядке. При этом запрос должен всегда строиться корректно.
2. Если метод `AddColumn` не был вызван, запрос должен начинаться с `SELECT * ...`.
3. Для простоты строки в запросе могут быть не выделены кавычками, как в примере.
4. Вызовы `AddFrom` должны перезаписывать название таблицы в классе.
5. Не забудьте `;` в конце каждого запроса.

------
