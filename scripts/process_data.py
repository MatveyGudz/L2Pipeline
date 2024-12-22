import sys
import matplotlib.pyplot as plt
from collections import defaultdict

def main():
    if len(sys.argv) != 2:
        print("Usage: python process_data.py <output_image_path>", file=sys.stderr)
        sys.exit(1)

    output_image = sys.argv[1]
    points = defaultdict(list)

    try:
        for line in sys.stdin:
            group, x, y = line.strip().split(',')
            points[group].append((int(x), int(y)))

        plt.figure(figsize=(10, 6))
        for group, coords in points.items():
            xs, ys = zip(*coords)
            plt.scatter(xs, ys, label=f'Group {group}')
        
        plt.title('Scatter Plot of Points')
        plt.xlabel('X Coordinate')
        plt.ylabel('Y Coordinate')
        plt.legend()
        plt.savefig(output_image)
        print(f"Graph saved to {output_image}")

    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
