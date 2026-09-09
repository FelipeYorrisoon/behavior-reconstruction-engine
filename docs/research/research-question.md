# Research Questions

## Purpose

This document defines the research questions that guide the investigation of the Behavior Reconstruction Engine.

The purpose of these questions is to transform the project's central problem into specific and investigable areas.

The research does not begin by assuming that the proposed model is novel or that existing security-analysis systems are incapable of solving the identified problem.

Instead, the investigation seeks to determine:

- what existing approaches already solve;
- which problems remain;
- whether a meaningful gap exists; and
- whether a structured evidence-preserving reconstruction model can provide a useful contribution.

---

## Primary Research Question

The primary research question is:

> How can heterogeneous security events be systematically transformed into explainable behavioral reconstructions while preserving explicit traceability between analytical conclusions and their underlying technical observations?

This question contains several independent research challenges.

A complete answer requires investigating how technical observations can be represented, related, interpreted, and traced across multiple levels of abstraction.

---

## Research Subquestions

### RQ1 — Event Representation

> How should heterogeneous technical observations be represented without losing their original identity, source, context, and provenance?

This question investigates the fundamental representation of an event.

The objective is to determine which properties must remain preserved when events from different sources are normalized into a common model.

Relevant concepts include:

- event identity;
- source;
- timestamp;
- actor;
- action;
- target;
- context;
- provenance.

---

### RQ2 — Evidence Representation

> What distinguishes a technical observation from evidence supporting an analytical claim, and how should that distinction be represented?

A raw event may contain information relevant to an investigation.

However, not every event necessarily supports every analytical conclusion.

This question investigates whether an explicit evidence layer can improve the representation of the connection between observations and analytical reasoning.

---

### RQ3 — Relationship Representation

> How should temporal, causal, contextual, and other relationships between technical observations be represented and distinguished?

Events may occur close together in time without being causally related.

Similarly, two observations may be connected through a shared process, user, file, host, or network artifact.

This research question investigates how different relationship types should be represented without automatically treating correlation as causation.

---

### RQ4 — Behavioral Interpretation

> How can multiple technical observations be systematically associated with higher-level behavioral interpretations?

Security analysts frequently reason at multiple levels of abstraction.

For example:

```text
Process Creation
+
Remote Authentication
+
Remote Execution
        ↓
Possible Lateral Movement