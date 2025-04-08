import torch
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt
import numpy as np

# Set random seed for reproducibility
torch.manual_seed(42)

# 1. Tensors - The fundamental data structure in PyTorch
print("=== PyTorch Tensors ===")

# Creating tensors
x = torch.tensor([1, 2, 3, 4])
print(f"Basic tensor: {x}")
print(f"Shape: {x.shape}, Dtype: {x.dtype}")

# Different ways to create tensors
zeros = torch.zeros(2, 3)  # 2x3 tensor of zeros
ones = torch.ones(2, 3)    # 2x3 tensor of ones
rand = torch.rand(2, 3)    # 2x3 tensor of random values from uniform distribution
randn = torch.randn(2, 3)  # 2x3 tensor of random values from normal distribution

print(f"\nZeros tensor:\n{zeros}")
print(f"\nRandom tensor:\n{rand}")

# Tensor operations
a = torch.tensor([1, 2, 3])
b = torch.tensor([4, 5, 6])

print(f"\nTensor a: {a}")
print(f"Tensor b: {b}")
print(f"a + b: {a + b}")
print(f"a * b (element-wise): {a * b}")
print(f"Dot product: {torch.dot(a, b)}")

# 2. Autograd - Automatic differentiation
print("\n=== PyTorch Autograd ===")

# Create tensors with requires_grad=True to track operations
x = torch.tensor([2.0], requires_grad=True)
y = x * x + 2
print(f"y = x^2 + 2 = {y.item()}")

# Compute gradient of y with respect to x
y.backward()
print(f"dy/dx at x=2: {x.grad.item()}")  # Should be 4 (derivative of x^2 is 2x)

# 3. Neural Network Module
print("\n=== PyTorch Neural Networks ===")

# Define a simple neural network
class SimpleNN(nn.Module):
    def __init__(self, input_size, hidden_size, output_size):
        super(SimpleNN, self).__init__()
        self.layer1 = nn.Linear(input_size, hidden_size)
        self.relu = nn.ReLU()
        self.layer2 = nn.Linear(hidden_size, output_size)
    
    def forward(self, x):
        x = self.layer1(x)
        x = self.relu(x)
        x = self.layer2(x)
        return x

# Create a model instance
model = SimpleNN(input_size=1, hidden_size=10, output_size=1)
print(f"Model structure:\n{model}")

# 4. Generate synthetic data
print("\n=== Training Example: Fitting a curve ===")

# Generate noisy data from y = 2x^2 + 1
x_train = torch.linspace(-2, 2, 100).reshape(-1, 1)
y_train = 2 * x_train**2 + 1 + 0.1 * torch.randn(x_train.size())

# Define loss function and optimizer
criterion = nn.MSELoss()
optimizer = optim.SGD(model.parameters(), lr=0.01)

# Training loop
losses = []
epochs = 500

for epoch in range(epochs):
    # Forward pass
    y_pred = model(x_train)
    loss = criterion(y_pred, y_train)
    losses.append(loss.item())
    
    # Backward pass and optimize
    optimizer.zero_grad()  # Clear gradients
    loss.backward()        # Compute gradients
    optimizer.step()       # Update weights
    
    if (epoch + 1) % 100 == 0:
        print(f'Epoch {epoch+1}/{epochs}, Loss: {loss.item():.4f}')

# Visualize results
with torch.no_grad():  # No need to track gradients for evaluation
    y_pred = model(x_train)

# Convert tensors to numpy for plotting
x_np = x_train.numpy()
y_np = y_train.numpy()
y_pred_np = y_pred.numpy()

plt.figure(figsize=(10, 5))

# Plot the training data and predictions
plt.subplot(1, 2, 1)
plt.scatter(x_np, y_np, label='Data')
plt.plot(x_np, y_pred_np, 'r-', label='Prediction')
plt.title('Model Predictions')
plt.legend()

# Plot the loss curve
plt.subplot(1, 2, 2)
plt.plot(losses)
plt.title('Training Loss')
plt.xlabel('Epoch')
plt.ylabel('MSE Loss')

plt.tight_layout()
plt.savefig('pytorch_training_results.png')
print("\nTraining complete! Results saved to 'pytorch_training_results.png'")

# 5. GPU Support
print("\n=== GPU Support ===")
print(f"Is CUDA available: {torch.cuda.is_available()}")
if torch.cuda.is_available():
    device = torch.device("cuda")
    print(f"Current CUDA device: {torch.cuda.get_device_name(0)}")
    
    # Moving tensors to GPU
    x_gpu = torch.tensor([1, 2, 3], device=device)
    # OR
    x_gpu = torch.tensor([1, 2, 3]).to(device)
    
    # Moving model to GPU
    model_gpu = model.to(device)
else:
    print("No GPU detected. Using CPU.")

print("\n=== PyTorch Basics Tutorial Complete ===")
