from trees.red_black_tree import BlackRedTree
def run_tests():
    tree = BlackRedTree()
    values = [10, 5, 15, 1, 7, 12, 20, 17, 13, 16, 35, 61, 55]
    print("Тест красно-чорного дерева:")
    print("\n1. Проверка вставки:")

    for value in values:
        tree.insert(value)

        if not tree.validate():
            print(f"ОШИБКА: дерево нарушило свойства после вставки {value}")
            return
    print(f"Успешно добавлено элементов: {len(values)}\nСтруктура дерева корректна.\n\n2. Проверка существующих элементов:")
    for value in values:
        assert tree.contains(value), f"Не найден элемент {value}"
    print("Все добавленные элементы найдены.\n\n3. Проверка отсутствующих элементов:")
    missing_values = [100, 200, -5, 999]
    for value in missing_values:
        assert not tree.contains(value), f"Неожиданно найден элемент {value}"
    print("Отсутствующие элементы не найдены.\n\n4. Итоговая проверка:")
    assert tree.validate(), "Проверка структуры дерева провалена."
    print("Все тесты пройдены успешно!")
if __name__ == "__main__":
    run_tests()