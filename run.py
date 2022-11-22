import ctypes


libObject = ctypes.cdll.LoadLibrary('./build/libsajjad.so')

# Test 1: send and receive numbers
x = 2
y = 3.14
libObject.add.argtypes = [ctypes.c_int, ctypes.c_float]
libObject.add.restype = ctypes.c_float
z = libObject.add(x, y)
print(z)

# Test 2: send number and receive string
num = 2
libObject.number2Word.argtypes = [ctypes.c_int]
libObject.number2Word.restype = ctypes.c_char_p
word = libObject.number2Word(num)
word = word.decode("utf-8")
print(word)

# Test 3: send string and receive number
word = "one"
word = word.encode()
libObject.word2Number.argtypes = [ctypes.c_char_p]
libObject.word2Number.restype = ctypes.c_int
num = libObject.word2Number(word)
print(num)

# Test 4: work with opencv
input_image_path = "io/input/image.jpg"
input_image_path = input_image_path.encode()
output_image_path = "io/output/result.jpg"
output_image_path = output_image_path.encode()
libObject.testOpenCV.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
libObject.testOpenCV(input_image_path, output_image_path)
