# ADR-0004: Event Identifier Representation

## Status

Accepted

## Context

The Behavior Reconstruction Engine requires a stable canonical identity for every observed Event.

The canonical identity must remain independent from the observable content of the event and independent from any identifier assigned by the original analysis source.

An event may contain a source-specific identifier, but that identifier belongs to the source provenance and must not become the canonical identity of the event.

The engine must also preserve the distinction between event identity and event ordering.

---

## Decision

The canonical `EventId` will be represented as a 128-bit identity.

The canonical identifier is independent of:

- the observable content of the event;
- the event timestamp;
- the event ordering;
- the identifier assigned by the original source.

The source-specific identifier, when available, will be preserved separately as part of provenance.

Conceptually:

    Event
    │
    ├── EventId
    │   └── canonical 128-bit identity
    │
    └── Provenance
        ├── source
        └── source_event_id

Therefore:

    EventId != source_event_id

and:

    EventId != hash(event content)

---

## Rationale

A 128-bit identity provides a sufficiently large identifier space for the canonical event model while remaining a fixed-size value suitable for implementation, storage, comparison, and serialization.

The use of a canonical identity also allows events from different sources to coexist without requiring their native identifiers to share a common namespace.

For example:

    CAPE event 42
    DRAKVUF event 42

may represent completely different observations.

They must therefore be able to receive different canonical identities even when their source-specific identifiers are identical.

---

## Identity Independence

The canonical identity must not be derived solely from observable event attributes.

For example, the following must not define the identity:

    hash(timestamp + actor + action + target)

Two events with identical observable content may still represent separate occurrences.

Therefore:

    identical content
            !=
    identical EventId

---

## Source Identity

A source may provide its own identifier.

For example:

    source = CAPE
    source_event_id = 42

The engine may preserve this information for provenance and traceability.

However:

    source_event_id

does not become:

    EventId

The canonical identity belongs to the Behavior Reconstruction Engine.

---

## Event Ordering

The EventId does not encode temporal ordering.

For example:

    Event A
    EventId = X

    Event B
    EventId = Y

does not imply:

    X < Y
    therefore
    A occurred before B

Event identity and event ordering are separate concepts.

Therefore:

    Event Identity != Event Ordering

---

## Consequences

### Positive

- Events from heterogeneous sources can coexist.
- Source-specific identifiers remain preserved.
- Canonical identity has a fixed size.
- Event identity remains independent from event content.
- Event identity remains independent from temporal ordering.
- Evidence relationships can reference canonical EventIds.
- Future serialization and storage can use a predictable representation.

### Negative

- A 128-bit identifier requires more storage than a 64-bit identifier.
- The implementation must define how 128-bit values are represented in C.
- Serialization format must be specified.
- Identifier generation must be specified.
- Source identifiers require separate storage when available.

---

## Future Work

The implementation must determine:

- the concrete C representation of the 128-bit EventId;
- byte ordering;
- serialization format;
- textual representation;
- identifier generation;
- comparison semantics;
- validation rules;
- interaction with source-specific identifiers;
- persistence requirements.

---

## Principle

> The canonical identity identifies the event occurrence, not its content, source identifier, or position in time.
