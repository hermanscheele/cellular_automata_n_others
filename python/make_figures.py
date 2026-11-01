"""Generate the static README figures in media/.

Run from anywhere:  python python/make_figures.py
"""
from pathlib import Path

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np

MEDIA = Path(__file__).resolve().parent.parent / "media"
GREEN, DEAD, GRID, INK, MUTED = "#22c55e", "#111418", "#2a2f36", "#e6e8eb", "#9aa3ad"
plt.rcParams.update({"font.family": ["Helvetica", "DejaVu Sans"], "font.size": 12, "text.color": INK})


def draw_cell_grid(ax, cells, highlight):
    for (i, j), alive in np.ndenumerate(cells):
        ax.add_patch(plt.Rectangle((j, 2 - i), 0.92, 0.92, color=GREEN if alive else DEAD))
    ax.add_patch(plt.Rectangle((1 - 0.06, 1 - 0.06), 1.04, 1.04, fill=False, ec=highlight, lw=2.5))
    ax.set_xlim(-0.15, 3.05); ax.set_ylim(-0.15, 3.05); ax.set_aspect("equal"); ax.axis("off")


def rules():
    cases = [
        ("Birth", "dead cell with exactly 3 neighbours",
         np.array([[1, 0, 1], [0, 0, 0], [0, 1, 0]]), 1),
        ("Survival", "live cell with 2 or 3 neighbours",
         np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1]]), 1),
        ("Death", "live cell with < 2 or > 3 neighbours",
         np.array([[1, 1, 0], [1, 1, 1], [0, 0, 0]]), 0),
    ]
    fig, axes = plt.subplots(1, 6, figsize=(12, 2.9), gridspec_kw={"width_ratios": [1, 1] * 3, "wspace": 0.45})
    fig.patch.set_facecolor(DEAD)
    for k, (title, sub, before, centre_after) in enumerate(cases):
        a, b = axes[2 * k], axes[2 * k + 1]
        after = before.copy(); after[1, 1] = centre_after
        draw_cell_grid(a, before, INK)
        draw_cell_grid(b, after, INK)
        a.set_title(title, loc="left", fontweight="bold", color=INK, pad=6)
        a.text(0, -0.55, sub, color=MUTED, fontsize=10.5, ha="left", va="top", clip_on=False)
        a.annotate("", xy=(1.42, 0.5), xytext=(1.06, 0.5), xycoords="axes fraction",
                   arrowprops=dict(arrowstyle="-|>,head_width=0.4,head_length=0.6", color=MUTED, lw=2))
    fig.savefig(MEDIA / "rules.png", dpi=150, bbox_inches="tight", facecolor=DEAD, pad_inches=0.25)
    plt.close(fig)


def brownian_motion(n_paths=10, n_steps=1000, dt=0.02, seed=7):
    # same model as cpp/src/brownian_motion.cpp: independent N(0, dt) steps in x and y over time t
    rng = np.random.default_rng(seed)
    xy = np.cumsum(rng.normal(0, np.sqrt(dt), size=(n_steps, n_paths, 2)), axis=0)
    t = np.arange(n_steps) * dt

    fig = plt.figure(figsize=(11, 4.6))
    fig.patch.set_facecolor(DEAD)
    ax = fig.add_subplot(projection="3d", facecolor=DEAD)
    shades = plt.cm.Greens(np.linspace(0.45, 0.95, n_paths))
    for k in range(n_paths):
        ax.plot(t, xy[:, k, 0], xy[:, k, 1], lw=1.1, color=shades[k])
    for axis in (ax.xaxis, ax.yaxis, ax.zaxis):
        axis.set_pane_color((0, 0, 0, 0)); axis.line.set_color(GRID)
        axis._axinfo["grid"]["color"] = GRID
    ax.set_xticklabels([]); ax.set_yticklabels([]); ax.set_zticklabels([])
    ax.set_xlabel("t", color=MUTED); ax.set_ylabel("x", color=MUTED); ax.set_zlabel("y", color=MUTED)
    ax.set_box_aspect((3, 1.2, 1.2), zoom=1.45)
    ax.view_init(14, -72)
    fig.savefig(MEDIA / "brownian_motion_3d.png", dpi=150, bbox_inches="tight", facecolor=DEAD)
    plt.close(fig)


if __name__ == "__main__":
    MEDIA.mkdir(exist_ok=True)
    rules()
    brownian_motion()
