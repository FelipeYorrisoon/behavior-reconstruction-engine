# Architecture Overview

## Purpose

This document defines the initial conceptual architecture of the Behavior Reconstruction Engine.

The architecture is intentionally high-level at this stage.

Implementation details will be added as the project evolves.

---

## Core Pipeline

```text
Input Sources
     │
     ▼
Event Ingestion
     │
     ▼
Canonical Event Model
     │
     ▼
Evidence Model
     │
     ▼
Correlation
     │
     ▼
Behavior Reconstruction
     │
     ▼
Sequence Reconstruction
     │
     ▼
Inference
     │
     ▼
Conclusion
     │
     ▼
Explanation / Output
```

---

## Core Principle

The system must preserve a traceable path:

```text
Conclusion
    ↓
Inference
    ↓
Sequence
    ↓
Behavior
    ↓
Relation
    ↓
Evidence
    ↓
Event
    ↓
Source
```

No analytical conclusion should become disconnected from the observations that support it.

---

## Layers

### Input Layer

Responsible for receiving data from external sources.

Potential sources include:

* sandbox telemetry;
* system tracing;
* behavioral engines;
* static-analysis systems;
* network telemetry.

The input layer should not determine the final analytical interpretation.

---

### Canonical Event Layer

Transforms heterogeneous input into a common internal representation.

Example:

```text
Source A:
    "CreateRemoteThread"

Source B:
    "remote_thread_create"

Canonical representation:
    PROCESS_REMOTE_THREAD_CREATE
```

The canonical model allows later components to reason about events independently of the original source format.

---

### Evidence Layer

Preserves:

* source;
* provenance;
* identifiers;
* timestamps;
* raw references;
* confidence;
* context.

---

### Correlation Layer

Determines relationships between events.

Examples:

```text
same process
same target
same file
same network endpoint
temporal proximity
dependency
```

Correlation must not automatically be interpreted as malicious behavior.

---

### Behavior Layer

Transforms evidence and relationships into higher-level behavioral entities.

Example:

```text
OpenProcess
VirtualAllocEx
WriteProcessMemory
CreateRemoteThread

        ↓

Process Injection
```

---

### Sequence Layer

Combines behaviors into larger sequences.

Example:

```text
Execution
    ↓
Credential Access
    ↓
Persistence
    ↓
Command and Control
```

The system must distinguish temporal ordering from causal dependency.

---

### Inference Layer

Produces higher-level interpretations.

Example:

```text
Observed:
    File read
    Compression
    HTTP POST

Inference:
    Possible data transmission
```

Inference is explicitly different from observation.

---

### Conclusion Layer

Represents the final analytical statement together with:

* supporting evidence;
* counter-evidence;
* reasoning;
* confidence;
* provenance.

---

## Design Constraint

The system should prefer an explanation that can be reconstructed from its underlying data instead of storing only a pre-generated textual explanation.

In other words:

```text
Explanation
```

should be a **view of the evidence graph**, not a disconnected artifact.
