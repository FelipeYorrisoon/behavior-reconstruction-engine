# Roadmap

The roadmap is intentionally incremental.

The project will prioritize correctness, explainability, provenance, and understanding over rapid feature accumulation.

---

# Phase 0 — Foundation

**Status: In progress**

Goals:

* define the project problem;
* establish repository structure;
* document research methodology;
* establish architectural principles;
* define the initial domain model;
* establish contribution and security policies.

Deliverables:

* [x] README
* [x] LICENSE
* [x] CONTRIBUTING
* [x] SECURITY
* [x] CHANGELOG
* [x] ROADMAP
* [x] architecture documentation
* [x] initial research documentation

---

# Phase 1 — Event Model

**Status: Planned**

Goals:

Create the first canonical representation of an observed event.

Topics:

* event identity;
* timestamps;
* event types;
* actors;
* targets;
* source provenance;
* ownership;
* memory layout;
* serialization considerations.

Deliverables:

* [ ] `Event` data structure
* [ ] event creation API
* [ ] event validation
* [ ] event lifecycle
* [ ] unit tests
* [ ] event documentation

---

# Phase 2 — Evidence Model

**Status: Planned**

Goals:

Represent the provenance and context of observations.

Deliverables:

* [ ] evidence structure
* [ ] source identification
* [ ] evidence references
* [ ] provenance tracking
* [ ] evidence validation
* [ ] tests
* [ ] documentation

---

# Phase 3 — Relations

**Status: Planned**

Goals:

Represent relationships between events and analytical entities.

Potential relations:

```text
precedes
same_process
same_target
depends_on
supports
contradicts
derived_from
```

Deliverables:

* [ ] relation model
* [ ] relation validation
* [ ] graph representation
* [ ] traversal
* [ ] tests

---

# Phase 4 — Behavior Engine

**Status: Planned**

Goals:

Transform related events into higher-level behavioral representations.

Deliverables:

* [ ] behavior model
* [ ] rule representation
* [ ] rule evaluation
* [ ] evidence requirements
* [ ] confidence representation
* [ ] explainability metadata

---

# Phase 5 — Sequence Reconstruction

**Status: Planned**

Goals:

Construct meaningful behavioral sequences from individual behaviors and their relationships.

Important distinction:

```text
Temporal order
```

is not necessarily equivalent to:

```text
Causal dependency
```

The engine must preserve this distinction.

Deliverables:

* [ ] sequence model
* [ ] dependency representation
* [ ] temporal relationships
* [ ] sequence traversal
* [ ] sequence explanation

---

# Phase 6 — Inference Engine

**Status: Planned**

Goals:

Represent higher-level interpretations while explicitly distinguishing them from observed facts.

Deliverables:

* [ ] inference model
* [ ] confidence
* [ ] supporting evidence
* [ ] counter-evidence
* [ ] uncertainty representation
* [ ] explanation generation

---

# Phase 7 — External Integrations

**Status: Planned**

Potential integrations:

* [ ] CAPE
* [ ] DRAKVUF
* [ ] capa
* [ ] Attack Flow
* [ ] STIX

Integrations will be implemented only when they provide measurable value to the core problem.

---

# Phase 8 — Analyst Interface

**Status: Planned**

Potential interfaces:

* [ ] CLI
* [ ] machine-readable output
* [ ] human-readable reports
* [ ] graph representation
* [ ] evidence traversal

---

# Phase 9 — Evaluation

**Status: Planned**

The project needs measurable evaluation.

Potential metrics:

* reconstruction accuracy;
* evidence coverage;
* false inference rate;
* provenance completeness;
* processing performance;
* memory usage;
* explainability;
* analyst effort reduction.

---

# Phase 10 — Release

**Status: Future**

Before the first stable release:

* [ ] architecture review;
* [ ] security review;
* [ ] documentation review;
* [ ] reproducible build;
* [ ] test coverage;
* [ ] examples;
* [ ] benchmark suite;
* [ ] release process;
* [ ] stable API policy.
