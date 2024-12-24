import ctypes
import numpy as np

# Загрузка DLL
lib = ctypes.CDLL('./DLL1.dll')

# Указываем сигнатуру функции divide_vector
lib.divide_vector.argtypes = [
    ctypes.POINTER(ctypes.c_double),  # Входной массив
    ctypes.POINTER(ctypes.c_double),  # Выходной массив
    ctypes.c_size_t,                 # Размер массива
    ctypes.c_double                  # Делитель
]
lib.divide_vector.restype = ctypes.c_double  # Функция возвращает double (время выполнения)

def divide_vector_cpp(vector, divisor):
    size = len(vector)
    input_array = (ctypes.c_double * size)(*vector)
    output_array = (ctypes.c_double * size)()

    # Вызов функции из DLL
    execution_time = lib.divide_vector(input_array, output_array, size, divisor)

    # Преобразование результата в NumPy массив
    result_array = np.array(output_array)
    return result_array, execution_time

# Тестирование
if __name__ == "__main__":
    # Создаём тестовый массив
    vector = np.random.rand(15000000)  # Массив из миллионов элементов
    divisor = 2.0

    # Вызов функции из DLL
    result_cpp, time_cpp = divide_vector_cpp(vector, divisor)

    print( result_cpp[:10])
    print(f"{time_cpp:.2f}")