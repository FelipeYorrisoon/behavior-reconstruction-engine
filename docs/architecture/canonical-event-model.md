# Canonical Event Model

## Purpose

The `Event` is the foundational object of the Behavior Reconstruction Engine.

It represents an occurrence observed by an analysis source.

The event model is intentionally designed before implementation.

---

## Definition

> An Event represents an observable occurrence during an analysis.

Examples:

```text
Process created
File opened
File written
Registry key created
OpenProcess called
WriteProcessMemory called
TCP connection established
DNS query performed
```

---

## Event vs Behavior

The system must maintain a strict conceptual distinction.

```text
Event
```

represents an observation.

```text
Behavior
```

represents an interpretation derived from one or more observations and relationships.

Example:

```text
Event:

WriteProcessMemory()
```

does not by itself necessarily mean:

```text
Process Injection
```

---

## Initial Fields

The initial conceptual event contains:

```text
Event
│
├── Identity
├── Timestamp
├── Type
├── Actor
├── Target
└── Source
```

These fields are provisional.

Implementation and research may introduce additional fields or modify the model.

---

## Identity

Every event requires an identifier that allows other objects to reference it.

Example:

```text
Event #104
```

The identifier is a logical identity within the event dataset.

It does not imply importance or severity.

---

## Timestamp

Events must preserve temporal information whenever the source provides it.

Timestamp information is important for:

* ordering;
* correlation;
* sequence reconstruction;
* temporal analysis.

A timestamp alone does not establish causality.

---

## Type

The event type describes what was observed.

Examples:

```text
PROCESS_CREATE
FILE_WRITE
MEMORY_WRITE
NETWORK_CONNECT
REGISTRY_CREATE
```

The representation of event types will be evaluated during implementation.

---

## Actor

The actor identifies the entity responsible for producing the event.

Examples:

```text
malware.exe
powershell.exe
explorer.exe
process ID 4212
```

---

## Target

The target identifies the entity affected by the event.

Examples:

```text
explorer.exe
C:\temp\payload.bin
registry key
192.0.2.10:443
```

Not every event necessarily has a target.

---

## Source

The source identifies where the event originated.

Examples:

```text
CAPE
DRAKVUF
capa
Sysmon
ETW
PCAP
```

The source should remain associated with the event so that later conclusions can be traced to the original observation.

---

## Provenance Requirement

An event should not lose its origin when transformed into the canonical model.

Conceptually:

```text
Original Event
      │
      ▼
Canonical Event
      │
      └── source/provenance
```

This allows later analysis to navigate from:

```text
Conclusion
    ↓
Evidence
    ↓
Canonical Event
    ↓
Original Source
```

---

## Future Questions

Before implementation, the following questions must be resolved:

* Should event IDs be sequential or globally unique?
* Should timestamps use a fixed representation?
* How should missing timestamps be represented?
* How should actor and target identities be normalized?
* How should source-specific metadata be preserved?
* Should raw source data be embedded or referenced?
* How should duplicate events be handled?
* How should malformed events be represented?
* What ownership rules apply to event memory?
* How should events be serialized?

These questions will be addressed through implementation and Architecture Decision Records.
