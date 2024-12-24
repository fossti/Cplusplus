import time
import random
def divide_vector(vector, divisor):
    start_time = time.time()  # Запуск таймера

    result = [x / divisor for x in vector]  # Деление элементов вектора

    end_time = time.time()  # Завершение таймера
    time_taken = end_time - start_time  # Вычисление времени выполнения

    return result, time_taken

    # Создаём тестовый вектор
vector = [random.random() for _ in range(15000000)]  # Вектор из миллиона случайных чисел
divisor = 2.0

#Деление
result, time_taken = divide_vector(vector, divisor)

# Вывод результатов
print(result[:10])
print(f"{time_taken:.2f}")