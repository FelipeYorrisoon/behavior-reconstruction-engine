# ADR-0002: Event Identity

## Status

Accepted

## Context

The Behavior Reconstruction Engine must preserve individual observations without assuming that identical observations represent the same occurrence.

Two events may contain identical timestamps, actors, actions, and targets while still representing separate occurrences in the original analysis data.

For example:

```text
Event A
10:01:00
powershell.exe
OPEN
C:\temp\a.txt

Event B
10:01:00
powershell.exe
OPEN
C:\temp\a.txt

The two events must remain distinct.



Automatically treating them as duplicates during ingestion could remove information required for temporal reconstruction, behavioral analysis, correlation, or later investigation.

## Decision

Each observed occurrence receives its own event identity.

Event identity must not be derived solely from the observable content of the event.

Two events with identical observable attributes are still distinct events unless an explicit later analytical process determines that they are duplicates.

Event identity is independent from event ordering.

Therefore:

    Event Identity != Event Ordering

A sequence number may describe an event's position within an analysis dataset, but it must not serve as the event's fundamental identity.


## Consequences

### Positive

- Individual observations are preserved.
- Repeated activity remains visible.
- Temporal reconstruction can retain repeated events.
- Deduplication becomes an explicit analytical operation.
- Event identity remains independent from semantic interpretation.
- Provenance can refer to individual observations.

### Negative

- The engine may store multiple events with identical content.
- Additional mechanisms may eventually be required to identify genuinely duplicated source records.
- Persistent identifiers require a representation suitable for storage and interchange.



## Rejected Alternative

Using the observable content of an event as its identity was rejected.

For example:

    hash(timestamp + actor + action + target)

would incorrectly imply that identical observations necessarily represent the same occurrence.

That assumption is unsafe for behavioral reconstruction.


## Future Work

The implementation must determine:

- the concrete representation of EventId;
- whether a 128-bit identifier is appropriate;
- how identifiers are serialized;
- how source identifiers relate to canonical identifiers;
- how explicit duplicate detection will work;
- how event ordering will be represented.

## Principle

> Identical observations do not necessarily represent identical events.
