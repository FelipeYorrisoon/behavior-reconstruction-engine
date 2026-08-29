# Related Work

## Purpose

This document records existing technologies and approaches relevant to the project.

The objective is not to reproduce them.

It is to understand the current ecosystem and identify potential complementary functionality.

---

## CAPE

CAPE provides automated malware analysis and sandboxing capabilities.

Relevant to this project because it can produce dynamic analysis information that could potentially serve as input to an evidence-preserving reconstruction engine.

---

## DRAKVUF

DRAKVUF provides virtualization-based malware analysis and monitoring capabilities.

Its telemetry represents another potential source of low-level observations.

---

## capa

capa identifies capabilities in executable files based on rules.

Its output represents a higher-level behavioral interpretation rather than raw system telemetry.

This makes it particularly interesting when studying the distinction between:

```text
Event
```

and:

```text
Behavior
```

---

## MITRE ATT&CK

ATT&CK provides a structured knowledge base describing adversary tactics, techniques, and procedures.

The project may use ATT&CK as a semantic vocabulary or mapping layer rather than attempting to recreate the knowledge base.

---

## MITRE Attack Flow

Attack Flow provides a representation for describing how adversary behaviors relate to one another.

It is relevant to the project's sequence and relationship model.

The project should therefore investigate interoperability rather than unnecessarily creating another incompatible attack-flow representation.

---

## GReAT-BeD

GReAT-BeD is relevant because it demonstrates research approaches to behavioral detection and graph-based reasoning.

Its architecture and research results should be studied to understand existing graph-rewriting approaches and their limitations.

---

## ANY.RUN

ANY.RUN provides interactive malware-analysis capabilities and behavioral visualization.

It represents an important example of how complex analysis results can be presented to analysts.

---

## Joe Sandbox

Joe Sandbox provides automated analysis, behavioral analysis, execution graphs, and security reporting.

It demonstrates that behavioral reconstruction and visualization are already commercially available.

Therefore, the project's differentiation cannot simply be:

> "We visualize malware behavior."

The differentiation must be more specific and evidence-based.

---

## Research Requirement

The project must continue investigating these technologies and their documentation, issues, discussions, papers, and user feedback.

No limitation should be treated as established solely from intuition.

Claims should be classified as:

```text
Strong Evidence
Moderate Evidence
Hypothesis
```

as described in `gap-analysis.md`.
