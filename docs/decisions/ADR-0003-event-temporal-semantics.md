# ADR-0003: Event Temporal Semantics

## Status

Accepted

## Context

The Behavior Reconstruction Engine must preserve temporal information without confusing temporal ordering with causality.

Security-analysis sources may provide timestamps with different levels of precision, different timezone information, or no timestamp at all.

The engine may also receive an event after the occurrence has already happened.

Therefore, the time at which an event occurred and the time at which the engine received the event are different concepts and must not be conflated.

## Decision

The canonical Event model will distinguish between:

    observed_at

and:

    ingested_at

### observed_at

`observed_at` represents the time at which the occurrence was observed or recorded by the original analysis source.

It represents source-provided temporal information.

### ingested_at

`ingested_at` represents the time at which the Behavior Reconstruction Engine received or processed the event.

It represents engine-side processing time.

These values must remain independent.

## Temporal Precision

The engine must preserve the precision actually provided by the source.

Examples:

    10:01:03

may have second-level precision.

    10:01:03.452

may have millisecond-level precision.

    10:01:03.452891

may have microsecond-level precision.

The engine must not invent precision that was not provided by the source.

## Missing Temporal Information

`observed_at` is optional.

An event remains valid even when the source does not provide an observation timestamp.

Missing temporal information must be represented explicitly as unknown or unavailable.

The engine must not replace an unknown timestamp with an artificial value such as:

    0

The absence of temporal information does not imply that the event did not occur.

## Timezone

Timezone information must be preserved when provided by the source.

The engine must not invent timezone information that was not supplied by the source.

## Temporal Ordering

Temporal information may be used to establish ordering relationships between events when the available evidence supports such ordering.

However, timestamps alone do not establish causality.

Therefore:

    Temporal Ordering != Causality

The system must not automatically transform:

    A occurred before B

into:

    A caused B

Causal relationships require additional evidence or explicit analytical inference.

## Equal Timestamps

Two or more events may have the same observed timestamp.

The engine must not arbitrarily determine an ordering between them unless another source of evidence establishes that ordering.

## Consequences

### Positive

- Source observation time is preserved.
- Engine ingestion time is preserved separately.
- Delayed event delivery can be detected or analyzed.
- Temporal reconstruction can remain faithful to source information.
- Missing timestamps do not invalidate events.
- Source precision is not artificially increased.
- Timezone information is not silently fabricated.
- Temporal ordering remains conceptually separate from causality.

### Negative

- The temporal model is more complex than storing a single timestamp.
- Consumers must handle optional temporal information.
- Different sources may provide incompatible levels of temporal precision.
- Later stages of the engine must explicitly handle events that cannot be temporally ordered.

## Rejected Alternatives

### Single Timestamp

Using a single timestamp for both source observation and engine ingestion was rejected.

This would lose information about delays between observation and processing.

### Artificial Default Timestamp

Replacing missing timestamps with a fixed value such as:

    0

was rejected.

This would transform unknown information into apparently valid information.

### Artificial Precision

Automatically assigning additional precision to timestamps was rejected.

This could create false confidence about the exact occurrence time.

### Timestamp-Based Causality

Assuming that an earlier timestamp implies that one event caused another was rejected.

Temporal precedence alone is insufficient evidence for causality.

## Future Work

The implementation must determine:

- the concrete representation of `observed_at`;
- the concrete representation of `ingested_at`;
- how temporal precision will be represented;
- how timezone information will be represented;
- how unknown temporal values will be represented in C;
- how temporal ordering will be calculated;
- how conflicting timestamps from different sources will be handled;
- how clock skew will be represented or detected;
- how temporal relationships will later interact with causal inference.

## Principle

> Preserve the time information that the evidence actually provides, and never turn temporal correlation into causality without additional evidence.
