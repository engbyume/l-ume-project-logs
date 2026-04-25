# Gravity Instructions (Antigravity)

## Skill Library Mandate
- **Always check the library:** Before starting ANY task, you MUST list and review the available skills in `~/.agents/skills/`.
- **Proactive Activation:** If any skill (e.g., `ai-hedge-fund`, `claude-code-best-practices`, `brainstorming`, etc.) is even 1% relevant to the task, you MUST activate and follow it.
- **Superpowered Execution:** Never settle for generic solutions when a specialized superpower is available.

## Project Context
- **Focus:** C++ firmware for IMU-based projects (L-UME).
- **Style:** Maintain surgical, precise code changes. Follow high-standard engineering patterns as defined in the `claude-code-best-practices` skill.
- **Hardware:** Dual IMU configurations, pitch delta zones, and haptic feedback motor control.

## Persistent Memory & Orchestration
- **claude-mem:** Utilize the `claude-mem-*` skills for cross-session context recall. Follow the 3-layer search workflow (Search -> Timeline -> Fetch) before assuming prior work status.
- **Archon:** Use the `archon` skill to manage complex, deterministic workflows. Prioritize isolated worktrees for parallel task development when appropriate.
- **Brainstorming Gated:** All significant architectural changes MUST pass the `brainstorming` skill hard-gate before implementation begins.

