import matplotlib.pyplot as plt

# Function to read data from file
def read_data(filename):
    iterations_kij = []
    times_kij = []
    iterations_ijk = []
    times_ijk = []
    iterations_jki = []
    times_jki = []
    with open(filename, 'r') as file:
        current_algorithm = None
        for line in file:
            line = line.strip()
            if line.startswith('KIJ'):
                current_algorithm = 'KIJ'
            elif line.startswith('IJK'):
                current_algorithm = 'IJK'
            elif line.startswith('JKI'):
                current_algorithm = 'JKI'
            else:
                data = line.split()
                if len(data) == 2:
                    iteration = int(data[0])
                    time = float(data[1])
                    if current_algorithm == 'KIJ':
                        iterations_kij.append(iteration)
                        times_kij.append(time)
                    elif current_algorithm == 'IJK':
                        iterations_ijk.append(iteration)
                        times_ijk.append(time)
                    elif current_algorithm == 'JKI':
                        iterations_jki.append(iteration)
                        times_jki.append(time)
    return iterations_kij, times_kij, iterations_ijk, times_ijk, iterations_jki, times_jki

# Read data from the file
try:
    iterations_kij, times_kij, iterations_ijk, times_ijk, iterations_jki, times_jki = read_data('output1.txt')
except FileNotFoundError:
    print("Error: Input file not found")
    exit()

# Plot the data
plt.plot(iterations_kij, times_kij, label='KIJ')
plt.plot(iterations_ijk, times_ijk, label='IJK')
plt.plot(iterations_jki, times_jki, label='JKI')

# Add labels and title
plt.xlabel('Iterations')
plt.ylabel('Time (seconds)')
plt.title('Comparison of Matrix Multiplication Algorithms')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()
