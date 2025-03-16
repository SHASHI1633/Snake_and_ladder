
import pandas as pd
from sqlalchemy import create_engine
import matplotlib.pyplot as plt
import seaborn as sns

# Database connection setup (Replace with actual credentials)
DB_URI = "mysql+mysqlconnector://root:password@localhost/snakeladderdb"
engine = create_engine(DB_URI)

# Load Game History Data
df_games = pd.read_sql("SELECT player_name, total_moves, duration_seconds, won FROM SnakeLadderGame", engine)

# Win Rate Analysis
win_rate = df_games.groupby("player_name")["won"].mean() * 100

# Plot Win Rate
plt.figure(figsize=(10,5))
sns.barplot(x=win_rate.index, y=win_rate.values, palette="coolwarm")
plt.xlabel("Player")
plt.ylabel("Win Rate (%)")
plt.title("Player Win Rate Analysis")
plt.xticks(rotation=45)
plt.show()

# Load Moves Data
df_moves = pd.read_sql("SELECT dice_roll, COUNT(*) AS frequency FROM SnakeLadderMoves GROUP BY dice_roll", engine)

# Plot Dice Roll Distribution
plt.figure(figsize=(10,5))
sns.barplot(x=df_moves["dice_roll"], y=df_moves["frequency"], palette="magma")
plt.xlabel("Dice Roll Value")
plt.ylabel("Frequency")
plt.title("Dice Roll Frequency Distribution")
plt.xticks(rotation=45)
plt.show()
